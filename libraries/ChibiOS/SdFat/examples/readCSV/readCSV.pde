/*
 *  This example reads a simple CSV, comma-separated values, file.
 *  Each line of the file has three values, a long and two floats.
 */
#include <SdFat.h>

// SD chip select pin
const uint8_t chipSelect = SS_PIN;

// file system object
SdFat sd;

// create Serial stream
ArduinoOutStream cout(Serial);

char fileName[] = "3V_FILE.CSV";
//------------------------------------------------------------------------------
// store error strings in flash to save RAM
#define error(s) sd.errorHalt_P(PSTR(s))
//------------------------------------------------------------------------------
// read and print CSV test file
void readFile() {
  long lg;
  float f1, f2;
  char c1, c2;
  
  // open input file
  ifstream sdin(fileName);
  
  // check for open error
  if (!sdin.is_open()) error("open");
  
  // read until input fails
  while (sdin >> lg >> c1 >> f1 >> c2 >> f2) {
    
    // error in line if not commas
    if (c1 != ',' || c2 != ',') error("comma");
    
    // print in six character wide columns
    cout << setw(6) << lg << setw(6) << f1 << setw(6) << f2 << endl;
  }
  // Error in an input line if file is not at EOF.
  if (!sdin.eof()) error("readFile");
}
//------------------------------------------------------------------------------
// write test file
void writeFile() {

  // create or open and truncate output file
  ofstream sdout(fileName);
  
  // write file from string stored in flash
  sdout << pstr(
    "1,2.3,4.5\n"
    "6,7.8,9.0\n"
    "9,8.7,6.5\n"
    "-4,-3.2,-1\n") << flush;

  // check for any errors
  if (!sdout) error("writeFile");
  
  // file is closed by destructor when it goes out of scope.
}
//------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  
  // initialize the SD card at SPI_HALF_SPEED to avoid bus errors with
  // breadboards.  use SPI_FULL_SPEED for better performance
  if (!sd.init(SPI_HALF_SPEED, chipSelect)) sd.initErrorHalt();
  
  // create test file
  writeFile();
  
  // read and print test
  readFile();  
  
  cout << "Done" << endl;
}
void loop() {}
