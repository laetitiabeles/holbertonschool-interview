#!/usr/bin/python3
"Method that determines if all the boxes can be opened"


def canUnlockAll(boxes):
    opened_boxes = {0}
    keys = set(boxes[0])

    while keys:
        new_keys = set()
        for key in keys:
            if key < len(boxes) and key not in opened_boxes:
                opened_boxes.add(key)
                new_keys.update(boxes[key])
        if not new_keys:
            break
        keys = new_keys

    return len(opened_boxes) == len(boxes)
