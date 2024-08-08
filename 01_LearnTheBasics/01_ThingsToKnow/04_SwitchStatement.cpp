double areaSwitchCase(int ch, vector<double> a) {
	double area = 0.0;
	switch(ch) {
		case 1:
			area = M_PI * a[0] * a[0];
			break;
		case 2: 
			area = a[0] * a[1];
			break;
	}
	return area;
}