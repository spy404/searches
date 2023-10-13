<?php

require_once __DIR__ . '/../vendor/autoload.php';
require_once __DIR__ . '/../Utils/ArrayHelpers.php';

function lowerBound(array $arr, int $elem)
{
    isSortedAscendingInts($arr);
    $hi = count($arr);
    $lo = 0;

    while ($lo < $hi) {
        $mid = $lo + floor(($hi - $lo) / 2);

        if ($arr[$mid] < $elem) {
            $lo = $mid + 1;
        } else {
            $hi = $mid;
        }
    }

    return $lo;
}
