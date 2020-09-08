#include "iostream"
#include "string"
using namespace std;
int main() {
	int chord;
	cout << "Welcome To chord family finder" << endl;


	cout << "please write one number of the chord listed below" << endl;
	cout << "1)   major" << endl;
	cout << "2)   minor" << endl;
	cin >> chord;


	if (chord == 1) {
		int scale_name;
		cout << "please write number of the chord listed below" << endl;
		cout << "1)   C" << endl;
		cout << "2)   D" << endl;
		cout << "3)   E" << endl;
		cout << "4)   F" << endl;
		cout << "5)   G" << endl;
		cout << "6)   A" << endl;
		cout << "7)   B" << endl;
		cin >> scale_name;

		if (scale_name == 1) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   C" << endl;
			cout << "2)   C#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of C major chord is :-" << endl;

				cout << "C major,	D minor, 	E minor, 	F major, 	G major, 	A minor, 	B diminished" << endl;
				cin >> which_scale;
			}

			if (which_scale == 2) {

				cout << "famalies of C# major chord is :-" << endl;

				cout << "C# major, D# minor, E# minor, F# major, G# major, A# major and B# diminished" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 2) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   D" << endl;
			cout << "2)   D#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of D major chord is :-" << endl;

				cout << "D major,	E minor,	 F# minor, 	G major, 	A major, 	B minor	C#diminished" << endl;
				cin >> which_scale;
			}

			if (which_scale == 2) {

				cout << "famalies of D# major chord is :-" << endl;

				cout << "Eb major, F minor, G minor, Ab major, Bb major, C minor and D diminished" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 3) {
			cout << "famalies of E major chord is :-" << endl;

			cout << "E major,	F# minor,	G# minor,	A major, 	Bmajor, 	C# minor,	D# diminished" << endl;
			cin >> scale_name;

		}
		if (scale_name == 4) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   F" << endl;
			cout << "2)   F#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of F major chord is :-" << endl;

				cout << "F major,	G minor,	Aminor, 	Bb major,	C major,	D minor,	C diminshed" << endl;
				cin >> which_scale;
			}

			if (which_scale == 2) {

				cout << "famalies of F# major chord is :-" << endl;

				cout << "F# major,	G# minor,	A# minor,	B major,	C# major,	D# minor,	E# diminished" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 5) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   G" << endl;
			cout << "2)   G#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of G major chord is :-" << endl;

				cout << "G major,	A minor,	B minor,	C major,	D major,	E minor, 	F# diminished" << endl;
				cin >> which_scale;
			}
			if (which_scale == 2) {

				cout << "famalies of G# major chord is :-" << endl;

				cout << "Ab major,    Bb minor,    C minor,    Db major,    Eb major,    F minor,    G diminished" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 6) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   A" << endl;
			cout << "2)   A#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of A major chord is :-" << endl;

				cout << " A major, B minor, C# minor, D major, E major, F# minor, and G# diminished" << endl;
				cin >> which_scale;
			}
			if (which_scale == 2) {

				cout << "famalies of A# major chord is :-" << endl;

				cout << "A# major,  C major,   D major,    D# major,    F major,    F# major,    G# major" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 7) {
			cout << "famalies of B major chord is :-" << endl;

			cout << "B major,	C# minor,	D# minor,	E major, 	F# major, 	C# minor,	A# diminished" << endl;
			cin >> scale_name;

		}
	}


	        //MINOR chords start from here 




	if (chord == 2) {
		int scale_name;
		cout << "please write number of the chord listed below" << endl;
		cout << "1)   C" << endl;
		cout << "2)   D" << endl;
		cout << "3)   E" << endl;
		cout << "4)   F" << endl;
		cout << "5)   G" << endl;
		cout << "6)   A" << endl;
		cout << "7)   B" << endl;
		cin >> scale_name;

		if (scale_name == 1) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   C" << endl;
			cout << "2)   C#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of C minor chord is :-" << endl;

				cout << "C minor,	D diminished, 	E flat, 	F minor, 	G minor, 	A flat, 	B flat" << endl;
				cin >> which_scale;
			}

			if (which_scale == 2) {

				cout << "famalies of C# minor chord is :-" << endl;

				cout << "C# minor, D# diminished, E# major, F# minor, G# minor, A major and B diminished" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 2) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   D" << endl;
			cout << "2)   D#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of D minor chord is :-" << endl;

				cout << "D minor,	E diminished,	F major, 	G minor, 	A minor, 	B bmajor,	C major" << endl;
				cin >> which_scale;
			}

			if (which_scale == 2) {

				cout << "famalies of D# minor chord is :-" << endl;

				cout << "D# minor,  	E# diminished,  	F# major,	G# minor, 	A# minor,   	B major,  	C# major" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 3) {
			cout << "famalies of E minor chord is :-" << endl;

			cout << "E minor,	F# diminished,  	G major, 	A minor,  	B minor,	C major,	D major" << endl;
			cin >> scale_name;

		}
		if (scale_name == 4) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   F" << endl;
			cout << "2)   F#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of F minor chord is :-" << endl;

				cout << "F minor,   	G diminished,   	Ab major,   	Bb minor,   	C minor, 	Db major,   	Eb major" << endl;
				cin >> which_scale;
			}

			if (which_scale == 2) {

				cout << "famalies of F# minor chord is :-" << endl;

				cout << "F# minor,  	G# diminished,  	A major, 	B minor, 	C# minor,   	D major, 	E major" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 5) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   G" << endl;
			cout << "2)   G#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of G minor chord is :-" << endl;

				cout << "G minor,   	A diminished,   	Bb major,   	C minor,    	D minor,    	Eb major,   	F major" << endl;
				cin >> which_scale;
			}
			if (which_scale == 2) {

				cout << "famalies of G# minor chord is :-" << endl;

				cout << "G# minor,  	A# diminished,  	B major,    	C# minor,   	D# minor,   	E major,    	F# major" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 6) {
			int which_scale;
			cout << "please select one from below" << endl;
			cout << "1)   A" << endl;
			cout << "2)   A#" << endl;
			cin >> which_scale;

			if (which_scale == 1) {

				cout << "famalies of A minor chord is :-" << endl;

				cout << " A minor,   	B diminished,   	C major,    	D minor,    	E minor,    	F major, 	  G major" << endl;
				cin >> which_scale;
			}
			if (which_scale == 2) {

				cout << "famalies of A# minor chord is :-" << endl;

				cout << "A# minor,  	B# diminished,  	C# major,   	D# minor,   	E# minor,   	F# major,   	G# major" << endl;
				cin >> which_scale;
			}
		}
		if (scale_name == 7) {
			cout << "famalies of B major chord is :-" << endl;

			cout << "B minor,   	C# diminished,   	D major,    	E minor,    	F# minor,   	G major,    	A major" << endl;
			cin >> scale_name;

		}
	}
	system("pause");
}