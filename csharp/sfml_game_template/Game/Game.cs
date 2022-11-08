using SFML.Graphics;
using SFML.System;
using SFML.Window;
using SFML.Audio;

namespace Program
{
    public class Game : GameLoop {
        public const uint DEFEAULT_WINDOW_HEIGHT = 480;
        public const uint DEFEAULT_WINDOW_WIDTH = 640;
        public const string WINDOW_TITLE = "SFML Template";

        public Game() : base(DEFEAULT_WINDOW_WIDTH, DEFEAULT_WINDOW_HEIGHT, WINDOW_TITLE, Color.Black) {
            
        }

        public override void LoadContent() {
            DebugUtility.LoadContent();
        }
        public override void Initialize() {

        }
        public override void Update(GameTime gameTime) {

        }
        public override void Draw(GameTime gameTime)
        {
            DebugUtility.DrawPerfomanceData(this, Color.White);
        }
    }
}