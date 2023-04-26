# MSZO Python HPC kurzus

## Fájlok:
* **High performance computing in Python.pdf**: Az előadásdiák pdf-ként
* **Időmérés_Mátrixszorzás példa.ipynb**: Rövid példák
  * Időmérés (time.time, %timeit)
  * Mátrixszorzás optimalizálása a futási idők plottolásával
  * Tömb elemeneinek összeadása, optimalizálás, a futási idők plottolásával
  * Cache kimutatása méréssel
* **vektor_szorzo.cpp**: A cache kimutatásához használt cpp program
* **Mandelbrot kirajzolása.ipynb**: A mandelbrot halmazos példa kódjai
* **mandelbrot.py**: rövid fálj, ami a *Mandelbrot kirajzolása.ipynb*-nek szükséges a multiprocessinges példához

## Telepítések
A közösen írt kódokhoz kell majd matplolib, numpy, és numba. Ez utóbbi csak Python 3.7-3.10 közötti verziókra működik jelenleg. A verzó ellenőrzéséhez használd a 'python --version' parancsot parancssorban, a telepítéshez a 'pip install numba' parancsot. Alternatívaként lehet [Google Colabban](https://colab.research.google.com/) dolgozni, ami böngészőben fut, semmit se kell telepíteni. Ekkor a több szálon futó programok kevésbé lesznek látványosak, mert a Google csak 1-2 processzormagot szokott adni.
