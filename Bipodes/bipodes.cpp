/*
  Bipodes: a C++ code for inferrence of persistence barcode distribution.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define Int int32_t
#define Poset vector<vector<bool>>

using namespace std;

// node structure
class node {
public:
  bool nonzero;
  Int id, id_org;
  double p, p_tmp;
  double theta, theta_prev, theta_sum, theta_sum_prev;
  double eta, eta_prev;
};

// Barcode with name
class Barcode {
public:
  string name;
  Int id; // index
  vector<double> co;//coordinates
};

int print_usage_and_exit(int exit_code) {
  cerr
      << "Usage: "
      << "bipodes"
      << "[options] < [file]" << endl
      << endl
      << "Options:" << endl
      << endl
      << "  --help          print this screen" << endl;
}

// output a barcode
ostream &operator<<(ostream& out, const Barcode& B){
  out << B.name << " : ";
  for (Int i = 0; i < (Int)B.co.size() - 1; ++i) {
out << B.co[i] << ", ";
  }
  out << B.co.back();
}

void print_barcodes(const vector<Barcode> bars) {
  for (const auto& it : bars) {
    cerr << it << endl;
  }
}

// compute zeta(.,B)
vector<double> compute_zeta(const Int B_id, const Poset& pos){
  vector<double> res;
  for (Int i = 0 ; i < pos.size() ; ++i ) {
    if (pos[i][B_id]){
      res[i] = 1;
    }
  }
  return res;
}

// compute mu(.,.)
vector<vector<double>> compute_mu(const Poset& pos){
  vector<vector<double>> res;

  return res;
}

// compute the MLE for eta : [\sum_{i=0}^N(\zeta(.,B_i))]/N
vector<double> compute_eta_MLE(const Poset& pos){
  vector<double> res(pos.size());
  Int N = pos.size();
  for (Int i=0 ; i < N ; ++i) {
    for (auto le : pos[i]) {
      if (le) {
        ++res[i];
      }
    }
    res[i] = res[i] / N;
  }
  return res;
}

vector<double> compute_proba_from_eta(const vector<double>& eta, const Poset& pos){

}

vector<double> compute_eta_from_proba(const vector<double>& proba, const Poset& pos){
  vector<double> res(pos.size());
  return res;
}

int main(int argc, char const *argv[]) {

  // arguments of the program
  for (size_t i = 1; i < argc; i++) {
    const string arg(argv[i]);
    if (arg == "--help"){
      print_usage_and_exit(0);
    }
  }

  vector<Barcode> barcode_input;
  double x;
  string name;
  Int id = 0;

  // input format:
  // <barcode name>\n
  // <b1 d1 b2 d2 ... bn dn>\n
  while (getline(cin, name)) {
    string line;
    getline(cin, line);
    cerr << "ligne: " << line << endl;
    if (cin) {
      Barcode B;
      B.name = name;
      B.id = id;
      ++id;
      istringstream iss(line);
      while (iss >> x){
        B.co.push_back(x);
      }

      if (B.co.size() % 2 == 1) {
        cerr << "At least one interval of barcode \"" << B.name << "\" miss data." << endl;
        exit(-1);
      }
      else{
        barcode_input.push_back(B);
      }
    }
    else {
      return 255;
    }
  }

  print_barcodes(barcode_input);
  Poset pos{{1,0,0},{0,1,0},{0,0,1}};
  vector<double> eta_mle = compute_eta_MLE(pos);
  for (auto& x : eta_mle){
    cerr << x << " ";
  }
  return 0;
}
