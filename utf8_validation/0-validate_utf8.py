#!/usr/bin/python3
"""
Module utf8 validation
"""


def validUTF8(data):
    """
    determines if a given data set represents a valid UTF-8 encoding.
    """
    num_bytes = 0
    msb_1 = 1 << 7
    msb_2 = 1 << 6

    for num in data:
        mask = 1 << 7
        if num_bytes == 0:
            while mask & num:
                num_bytes += 1
                mask = mask >> 1

            if num_bytes == 0:
                continue

            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            if not (num & msb_1 and not (num & msb_2)):
                return False

        num_bytes -= 1

    return num_bytes == 0
