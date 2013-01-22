int * buffered_array(const int array[], int len, int incr) {
	int * p1;
	p1 = new int [len + incr];
	for (int i = 0; i < len; ++i) {
		p1[i] = array[i];
	}
	return p1;
}
