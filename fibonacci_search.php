<?php

function fibonacciPosition(int $n, array &$m = [])
{
    if (isset($m[$n])) {
        return $m[$n];
    }
    if ($n < 2) {
        return $n;
    }

    $m[$n] = fibonacciPosition($n - 1, $m) + fibonacciPosition($n - 2, $m);

    return $m[$n];
}

print fibonacciPosition(59);
