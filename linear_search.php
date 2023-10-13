<?php

function linearSearch($list, $target)
{
    $n = sizeof($list);
    for ($i = 0; $i < $n; $i++) {
        if ($list[$i] == $target) {
            return $i + 1;
        }
    }

    return -1;
}
