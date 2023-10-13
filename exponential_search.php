<?php

/**
 * @param  Array  $arr
 * @param  int  $value
 * @param  int  $floor
 * @param  int  $ceiling
 * @return int
 **/
function binarySearch($arr, $value, $floor, $ceiling)
{
    $mid = floor(($floor + $ceiling) / 2);

    if ($arr[$mid] === $value) {
        return (int) $mid;
    }

    if ($floor > $ceiling) {
        return -1;
    }

    if ($arr[$mid] > $value) {
        return binarySearch($arr, $value, $floor, $mid - 1);
    } else {
        return binarySearch($arr, $value, $mid + 1, $ceiling);
    }
}

/**
 * @param  Array  $arr
 * @param  int  $value
 * @return int
 */
function exponentialSearch($arr, $value)
{
    if ($arr[0] === $value) {
        return 0;
    }

    $i = 1;
    $length = count($arr);
    while ($i < $length && $arr[$i] <= $value) {
        $i = $i * 2;
    }
    $floor = $i / 2;
    $ceiling = min($i, $length);

    return binarySearch($arr, $value, $floor, $ceiling);
}
