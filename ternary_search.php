<?php

function ternarySearchByRecursion($arr, $key, $low, $high)
{
    if ($high < $low) {
        return null;
    }

    $mid1 = floor($low + ($high - $low) / 3);
    $mid2 = floor($high - ($high - $low) / 3);

    if ($arr[$mid1] === $key) {
        return $mid1;
    }

    if ($arr[$mid2] === $key) {
        return $mid2;
    }

    if ($key < $arr[$mid1]) {
        return ternarySearchByRecursion($arr, $key, $low, $mid1 - 1);
    } elseif ($key > $arr[$mid2]) {
        return ternarySearchByRecursion($arr, $key, $mid2 + 1, $high);
    } else {
        return ternarySearchByRecursion($arr, $key, $mid1 + 1, $mid2 - 1);
    }
}

function ternarySearchIterative($arr, $key)
{
    $low = 0;
    $high = count($arr) - 1;

    while ($high >= $low) {
        $mid1 = floor($low + ($high - $low) / 3);
        $mid2 = floor($high - ($high - $low) / 3);

        if ($arr[$mid1] === $key) {
            return $mid1;
        }

        if ($arr[$mid2] === $key) {
            return $mid2;
        }

        if ($key < $arr[$mid1]) {
            $high = $mid1 - 1;
        } elseif ($key > $arr[$mid2]) {
            $low = $mid2 + 1;
        } else {
            $low = $mid1 + 1;
            $high = $mid2 - 1;
        }
    }

    return null;
}
