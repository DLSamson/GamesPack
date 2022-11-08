using System;
using SFML.Graphics;
using SFML.System;
using SFML.Window;

namespace Program {
    public abstract class GameLoop {
        public const int TARGET_FPS = 60;
        public const float TIME_UNTIL_UPDATE = 1f/TARGET_FPS;

        public RenderWindow Window {
            get;
            protected set;
        }

        public GameTime GameTime {
            get; 
            protected set;
        }
        public Color WindowClearColor {
            get;
            protected set;
        }

        protected GameLoop(uint windowWidth, uint windowHeight, string windowTitle, Color windowClearColor) {
            this.WindowClearColor = windowClearColor;
            this.Window = new RenderWindow(new VideoMode(windowWidth, windowHeight), windowTitle);
            this.GameTime = new GameTime();
        }

        public void Run() {
            LoadContent();
            Initialize();

            float totalTimeBeforeUpdate = 0f;
            float previousTimeElapsed = 0f;
            float deltaTime = 0f;
            float totalTimeElapsed = 0f;

            Clock clock = new Clock();

            while(Window.IsOpen) {
                Window.DispatchEvents();

                totalTimeBeforeUpdate = clock.ElapsedTime.AsSeconds();
                deltaTime = totalTimeElapsed - previousTimeElapsed;
                previousTimeElapsed = totalTimeElapsed;

                totalTimeBeforeUpdate += deltaTime;

                if(totalTimeElapsed >= TIME_UNTIL_UPDATE) {
                    GameTime.Update(totalTimeBeforeUpdate, clock.ElapsedTime.AsSeconds());
                    totalTimeElapsed = 0f; 

                    Update(GameTime);

                    Window.Clear(WindowClearColor);
                    Draw(GameTime);
                    Window.Display();
                }   

            }
        }

        public abstract void LoadContent();
        public abstract void Initialize();
        public abstract void Update(GameTime gameTime);
        public abstract void Draw(GameTime gameTime);
    }
}