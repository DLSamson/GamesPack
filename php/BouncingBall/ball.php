<?php

$width = 45;
$height = 30;

$ball = ['x'=> 10, 'y'=>10];
$vector = ['x'=> 1, 'y'=>1];

for ($i = 0; $i < 100000; $i++) {
    $ball['x'] += $vector['x'] * rand(0, 1);
    $ball['y'] += $vector['y'] * rand(0, 1);

    if($ball['x'] >= $width-1 || $ball['x'] < 1) {
        $vector['x'] *= -1;
        $ball['x'] += $vector['x'];
    }
    if( $ball['y'] >= $height-1 || $ball['y'] < 1) {
        $vector['y'] *= -1;
        $ball['y'] += $vector['y'];
    }

    $field = getEmptyField($height, $width);
    $field[$ball['y']][$ball['x']] = '@';
    drawFrame($field, 0.02);
}


function getEmptyField($height, $width) {
    $field = [];
    for($y = 0; $y < $height; $y++){
        for($x = 0; $x < $width; $x++){
            if($x == 0 || $x == $width-1 || $y == 0 || $y == $height-1) {
                $field[$y][$x] = '#';
            }
            else {
                $field[$y][$x] = ' ';
            }
        }
    }
    return $field;
}
function drawFrame($frame, $delay) {
    ob_start();
    clear();
    printField($frame);
    delay($delay);
    ob_end_flush();
}
function clear() {
    //Add cross-platform decision;
//    popen('cls', 'w');
    print("\033[2J\033[;H");
    echo "\r";
}
function printField($field){
    foreach ($field as $y) {
        foreach ($y as $x) {
            print($x);
        }
        print("\n");
    }
}
function delay($time) {
    usleep($time * 1000000);
}