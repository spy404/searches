<?php

function interpolationSearch($arr, $key)
{
    $length = count($arr) - 1;
    $low = 0;
    $high = $length;
    $position = -1;
    while ($low <= $high && $key >= $arr[$low] && $key <= $arr[$high]) {
        $delta = ($key - $arr[$low]) / ($arr[$high] - $arr[$low]);
        $index = $low + floor(($high - $low) * $delta);

        $indexValue = $arr[$index];

        if ($indexValue === $key) {
            $position = $index;
            return (int) $position;
        } elseif ($indexValue < $key) {
            $low = $index + 1;
        } elseif ($indexValue > $key) {
            $high = $index - 1;
        }
    }

    return null;
}
