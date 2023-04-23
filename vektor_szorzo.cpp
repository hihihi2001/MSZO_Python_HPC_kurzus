#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <time.h>

using namespace std;

double dot(double* a, double* b, size_t n);
double* rand_vec(size_t n);

string file_name = "dot_product_time.csv";
int array_sizes[] = { 2, 3, 4, 5, 6, 7, 8, 9, 11, 13, 15, 18, 21, 25, 30, 36, 42, 50, 59, 70, 83, 98, 116, 137, 162, 192, 227, 268, 317, 375, 443, 524, 619, 732, 866, 1024, 1097, 1265, 1458, 1681, 1938, 2235, 2577, 2971, 3425, 3949, 4553, 5249, 6051, 6977, 8043, 9273, 10691, 12326, 14211, 16384, 17559, 20244, 23340, 26908, 31023, 35766, 41234, 47539, 54808, 63188, 72849, 83987, 96829, 111634, 128702, 148381, 171068, 197223, 227378, 262144, 280958, 305414, 331998, 360896, 392309, 426457, 463576, 503927, 547790, 595471, 647302, 703645, 764892, 831470, 903844, 982516, 1068037, 1161001, 1262058, 1371910, 1491325, 1621133, 1762240, 1915630, 2082371, 2263625, 2460657, 2674838, 2907662, 3160752, 3435872, 3734938, 4060036, 4413431, 4797587, 5215180, 5669121, 6162575, 6698980, 7282076, 7915925, 8604945, 9353940, 10168129, 11053187, 12015283, 13061122, 14197993, 15433819, 16777216};
int trial_nums[] = { 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 500, };

int main()
{
	ofstream fout(file_name, fstream::out);
	fout << "n,time\n";
	srand(time(NULL));
	

	for (int i = 0; i < 126; i++)
	{
		int n = array_sizes[i];
		int trial = 0.1 * trial_nums[i];
		double time = 0.0;
		for (int k = 0; k < 100; k++)
		{
			double* a = rand_vec(n);
			double* b = rand_vec(n);
			auto start = std::chrono::high_resolution_clock::now();


			for (int j = 0; j < trial; j++) {
				double c = dot(a, b, n);
			}


			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			time += (double)duration.count();
			delete a; delete b;
		}


		time = 1e-9 * time / trial / 10;
		cout << i << '\t' << time << endl;
		fout << n << ',' << time << '\n';
	}


	fout.flush(); fout.close();
	return 0;
}

double dot(double* a, double* b, size_t n)
{
	double ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret += a[i] * b[i];
	}
	return ret;
}

double* rand_vec(size_t n)
{
	double* ret = new double[n];
	for (int i = 0; i < n; i++)
	{
		ret[i] = (double)rand() / RAND_MAX;
	}
	return ret;
}
