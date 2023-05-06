#!/usr/bin/python3
"""
Interview task: Log parsing
"""
import sys


def print_all_stats():
    """Print all metrics"""
    print("File size: {}".format(file_size))

    for key in sorted(status_codes.keys()):
        if status_codes[key]:
            print("{}: {}".format(key, status_codes[key]))


if __name__ == "__main__":
    status_codes = {"200": 0, "301": 0, "400": 0, "401": 0,
                    "403": 0, "404": 0, "405": 0, "500": 0}
    file_size, qty_lines = 0, 0

    try:
        # Read stdin line by line
        for line in sys.stdin:
            try:
                # Processing all the data:
                element = line.split()

                # Compute the total file_size:
                file_size += int(element[-1])

                # Compuete the qty of lines have an specific status code:
                if element[-2] in status_codes:
                    status_codes[element[-2]] += 1
            except Exception:
                pass

            # Print all data after every 10 lines:
            if qty_lines == 9:
                print_all_stats()
                qty_lines -= 1
            qty_lines += 1

    # Contemplate case: keyboard interruption (CTRL + C)
    except KeyboardInterrupt:
        print_all_stats()
        raise
    print_all_stats()
