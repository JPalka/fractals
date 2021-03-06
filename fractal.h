#ifndef FRACTAL_H
#define FRACTAL_H

#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include "zoomlist.h"
#include "pixel.h"
#include "colorscheme.h"
#include "bitmap.h"
#include "histogram.h"

class Fractal {

	protected:
		uint _width; // szerokość obrazu
		uint _height; // wysokość obrazu
		ZoomList _zoomList; // lista zoomów
		std::vector<Pixel> _fractal; // vector pixeli
		std::unique_ptr<ColorScheme> _coloringMethod { nullptr }; // Metoda kolorowania pixeli
		Bitmap _outputFile; // Plik wynikowy. TODO: Dodać możliwość innych typów ( jpg, png, whatever )
		int _maxIterations; // Maksymalna liczba iteracji na piksel.
		virtual int getIterations ( double x, double y ) = 0; // oblicza ilosc iteracji
		// oblicza dane fraktala dla pixela ( iteracje, wartość funkcji itp. dane do kolorowania pixela )
		virtual void calculatePixelData ( Pixel &pixel ) = 0;
		Fractal ( );
		void printMessage ( std::string message );
		void scalePixelCoordinates(Pixel &pixel, int x, int y);
	public:
		void calculateFractal (); // Oblicza fraktal
		void setDimensions ( int width, int height );
		std::string _fractalName {};
		void setMaxIterations ( int iterations );
		void setColorScheme ( ColorScheme &colorScheme );
		void addZoom ( Zoom zoom );
		/* Koloruje piksele fraktala na podstawie danych policzonych wczesniej i schematu kolorowania
		 */
		void colorFractal ();
		// Zapisuje fractal do pliku
		void save ();
		virtual ~Fractal () {}
		ColorScheme &getColorScheme ();
	private:

};

#endif // FRACTAL_H
