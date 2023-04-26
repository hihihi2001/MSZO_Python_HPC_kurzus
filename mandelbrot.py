import numpy as np
import numba as nb

@nb.njit
def compute_row(j, division, top_left, size, iteration_limit):
    row = np.zeros(division[0], dtype=np.int64)
    imag = top_left.imag + j * size.imag / division[1]
    for i in range(division[0]):
        real = top_left.real + i * size.real / division[0]
        c = complex(real, imag)
        z = complex(0, 0)
        iteration = 0

        # fő iteráció:
        while (iteration < iteration_limit) and (z.real ** 2 + z.imag ** 2 < 4.0):
            z = z ** 2 + c
            iteration += 1

        row[i] = -iteration

    return row