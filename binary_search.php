<?php

function binarySearchIterative($list, $target)
{
    $first = 0;
    $last = count($list) - 1;


    while ($first <= $last) {
        $mid = ($first + $last) >> 1;


        if ($list[$mid] == $target) {
            return $mid;
        } elseif ($list[$mid] > $target) {
            $last = $mid - 1;
        } elseif ($list[$mid] < $target) {
            $first = $mid + 1;
        }
    }

    return null;
}

function binarySearchByRecursion($list, $target, $start, $end)
{
    if (count($list) == 0) {
        return null;
    }

    if (count($list) < 2) {
        return $list[0] == $target ? 0 : null;
    }

    if ($start > $end) {
        return null;
    }


    $mid = ($start + $end) >> 1;


    if ($list[$mid] == $target) {
        return $mid;
    } elseif ($list[$mid] > $target) {
        return binarySearchByRecursion($list, $target, $start, $mid - 1);
    } elseif ($list[$mid] < $target) {
        return binarySearchByRecursion($list, $target, $mid + 1, $end);
    }

    return null;
}
