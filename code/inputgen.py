import sys
from random import randint
if __name__ == "__main__":
    if len(sys.argv) != 6:
        print("Usage: python script.py dimx dimy num_wires filename")
        sys.exit(1)

    dimx, dimy, numwires, noise, name = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), int(sys.argv[4]), sys.argv[5]

    with open(f"./inputs/timeinput/{name}", 'w') as file:
        file.write(f"{dimx} {dimy}\n")
        file.write(f"{numwires}\n")
        for i in range(numwires):
            while (True):
                x0 = randint(0, dimx-1)
                x1 = randint(max(0, x0 - 2 * noise), min(x0 + 2 * noise, dimx-1))
                y0 = randint(0, dimy-1)
                y1 = randint(max(0, y0 - 2 * noise), min(y0 + 2 * noise, dimy-1))

                if (x0 != x1 or y0 != y1):
                    break
            file.write(f"{x0} {y0} {x1} {y1}\n")
