<?php

function jumpSearch($list, $key)
{
    $num = count($list);

    $step = (int)sqrt($num);
    $prev = 0;

    while ($list[min($step, $num) - 1] < $key) {
        $prev = $step;
        $step += (int)sqrt($num);
        if ($prev >= $num) {
            return -1;
        }
    }

    while ($list[$prev] < $key) {
        $prev++;
        if ($prev == min($step, $num)) {
            return -1;
        }
    }

     return $list[$prev] === $key ? $prev : -1;
}
