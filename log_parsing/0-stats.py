#!/usr/bin/python3
"""Reads stdin line by line and computes metrics.

Input format: <IP> - [<date>] "GET /projects/260 HTTP/1.1" <status> <size>
Only lines that exactly match the format are processed.
After every 10 lines and on KeyboardInterrupt prints stats.
"""
import re
import sys


def print_stats(total_size, status_counts):
    print("File size: {}".format(total_size))
    for code in sorted(status_counts, key=int):
        count = status_counts[code]
        if count:
            print("{}: {}".format(code, count))


def main():
    total_size = 0
    status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
    status_counts = {code: 0 for code in status_codes}

    # Regex to match the required log format
    pattern = re.compile(
        r"^\S+ - \[[^\]]+\] \"GET /projects/260 HTTP/1\.1\" "
        r"(\d{3}) (\d+)$"
    )

    line_count = 0
    try:
        for line in sys.stdin:
            line = line.rstrip('\n')
            match = pattern.match(line)
            if match:
                status, size = match.group(1), match.group(2)
                try:
                    size_i = int(size)
                    total_size += size_i
                except ValueError:
                    # If file size is not an integer, skip adding
                    pass
                if status in status_counts:
                    status_counts[status] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        # On Ctrl+C print stats and exit gracefully
        print_stats(total_size, status_counts)
        sys.exit(0)


if __name__ == '__main__':
    main()
