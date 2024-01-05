// google-beginnerquest2023.cpp
// James Diroff II
// @jimdiroffii
// Jan 02, 2024

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>

/* Caesar Cipher Solver */
std::string caesar(const std::string& str, int shift) {
  std::string result{};
  
  // substitution
  for (auto ch : str) {
    if (isalpha(ch)) {
      auto base = islower(ch) ? 'a' : 'A';
      ch = static_cast<char>((ch - base + shift) % 26 + base);
    }
    result += ch;
  }

  return result;
}

/* Brute force Caesar */
void brutus(const std::string& str) {
  for (int i = 1; i <= 25; ++i) {
    std::string decrypted = caesar(str, i);
    std::cout << std::left << "shift " << std::setw(3) << i  << ": " << decrypted << '\n';
  }
}

/* Sequence Caesar - Multiple shifts based on key */
std::string seqCaesar(const std::string& cipher, const std::vector<int>& key) {
  std::size_t keyIndex{};
  std::size_t keySize = key.size();

  std::string result{};

  for (auto ch : cipher) {
    if (isalpha(ch)) {
      if (keyIndex >= keySize) {
        keyIndex = 0;
      }

      auto base = islower(ch) ? 'a' : 'A';
      ch = static_cast<char>((ch - base + key[keyIndex++]) % 26 + base);
    }
    result += ch;
  }

  return result;
}

/* Mapped Caesar */
std::string mapCaesar(const std::string& cipher, const std::map<char, char> key) {
  std::string result{};

  for (auto ch : cipher) {
    if (key.find(ch) != key.end()) {
      result += key.at(ch);
    }
    else {
      result += ch;
    }
  }
  return result;
}

/* Brute Force Tranposition */
void replaceSpecialSequence(std::string& input) {
  const std::string specialSequence = "␣"; // Define the special sequence
  size_t pos = 0;
  while ((pos = input.find(specialSequence, pos)) != std::string::npos) {
    input.replace(pos, specialSequence.length(), "_"); // Replace with underscore
    pos += 1; // Move past the underscore
  }
}

void print2DVector(const std::vector<std::vector<char>>& vec) {
  for (const auto& row : vec) {
    std::cout << "{";
    for (size_t i = 0; i < row.size(); ++i) {
      std::cout << row[i];
      if (i < row.size() - 1) {
        std::cout << ",";
      }
    }
    std::cout << "}" << std::endl; // Print each row on a new line
  }
}

std::vector<std::vector<char>> rearrangeColumns(const std::vector<std::vector<char>>& matrix) {
  const std::vector<int> newOrder = { 2, 0, 3, 5, 1, 4 };
  std::vector<std::vector<char>> rearranged(matrix.size(), std::vector<char>(matrix[0].size(), ' '));

  for (size_t row = 0; row < matrix.size(); ++row) {
    for (size_t col = 0; col < matrix[0].size(); ++col) {
      rearranged[row][col] = matrix[row][newOrder[col]];
    }
  }

  return rearranged;
}

std::string buildStringFrom2DArray(const std::vector<std::vector<char>>& matrix) {
  std::string result;
  for (const auto& row : matrix) {
    for (char ch : row) {
      if (ch != ' ') { // Skip spaces if you don't want them in the final string
        result += ch;
      }
    }
  }
  return result;
}

void transpositionIteration(std::string input) {
  replaceSpecialSequence(input); // Replace special sequences in the input
  std::vector<std::vector<char>> result{};
  size_t numColumns = 1;
  while (true) {
    size_t numRows = (input.length() + numColumns - 1) / numColumns; // Ceiling division
    std::vector<std::vector<char>> matrix(numRows, std::vector<char>(numColumns, ' ')); // Fill with spaces for alignment

    for (size_t i = 0; i < input.size(); ++i) {
      size_t row = i % numRows;
      size_t col = i / numRows;
      matrix[row][col] = input[i];
    }

    print2DVector(matrix);

    char choice;
    std::cout << "Continue with the next iteration? (y/n): ";
    std::cin >> choice;
    if (choice != 'y') {
      result = matrix;
      break;
    }

    ++numColumns;
  }

  result = rearrangeColumns(result);
  print2DVector(result);
  std::cout << buildStringFrom2DArray(result);
}

int main()
{
  /* {
    std::string cipher0 = "Naljnl, Pnrfne jnf n fxvyyrq pbzzhavpngbe, naq ur hfrq n inevrgl bs zrgubqf gb xrrc uvf zrffntrf frperg sebz uvf rarzvrf. Bar bs gurfr zrgubqf jnf gur Pnrfne pvcure, n fvzcyr grpuavdhr gb boshfpngr pbzzhavpngvbaf. SYNT{ebgngr_gung_nycunorg}";
    std::cout << "cipher: " << cipher0 << "\n";
    std::cout << "text:" << caesar(cipher0, 13) << "\n\n";
    //brutus(cipher0);
  }*/

  /* {
    std::string cipher1 = "Vhi Nixgnije tkplwr zu a tglpcltzasgtmu sldsxatlvisf czrhij. Ik ks e eoig sshhzutmuakgd zwrjkor gf kje Gsejcr gapygr, azitj uwws r uirylv uhmxt mclyw tf gngjygv tlw eevivw mvuseye. WNAK{yek_xikyy_nktl_at}";
    std::cout << "cipher: " << cipher1 << "\n";
    std::vector<int> key = { 24, 0, 22, 8, 0, 9 };
    std::cout << seqCaesar(cipher1, key) << "\n\n";
  }*/

  /* {
    std::string cipher2 = "PDV KLRBC IOEXQ AEY TLGMF EJVO PDV NSWH ZEU.\nPDRF PVYP RF S MSQUOSG, XDRBD GVSQF PDSP RP BEQPSRQF SNN 26 NVPPVOF EA PDV VQUNRFD SNMDSIVP.PDRF GSCVF RP RZVSN AEO AOVKLVQBH SQSNHFRF, SF PDV BOHMPSQSNHFP BSQ BEGMSOV PDV AOVKLVQBH EA NVPPVOF RQ PDV BRMDVOPVYP PE PDV CQEXQ AOVKLVQBH EA NVPPVOF RQ PDV VQUNRFD NSQULSUV.\nAEO VYSGMNV, PDV GEFP BEGGEQ NVPPVO RQ PDV VQUNRFD NSQULSUV RF V.RA PDV GEFP BEGGEQ NVPPVO RQ PDV BRMDVOPVYP RF Y, PDVQ PDV BOHMPSQSNHFP BSQ SFFLGV PDSP Y RF NRCVNH PE IV S FLIFPRPLPREQ AEO V.\nEPDVO BEGGEQ NVPPVOF RQ PDV VQUNRFD NSQULSUV RQBNLZV P, S, E, R, Q, F, SQZ D.PDV BOHMPSQSNHFP BSQ LFV PDRF RQAEOGSPREQ PE GSCV VZLBSPVZ ULVFFVF SIELP PDV EPDVO FLIFPRPLPREQF RQ PDV BRMDVOPVYP.\nANSU{ QEX_RJV_NVSOQVZ_GH_SIBF }";
    std::cout << "cipher: " << cipher2 << "\n";
    std::map<char, char> key{};
    key['A'] = 'F';
    key['B'] = 'C';
    key['C'] = 'K';
    key['D'] = 'H';
    key['E'] = 'O';
    key['F'] = 'S';
    key['G'] = 'M';
    key['H'] = 'Y';
    key['I'] = 'B';
    key['J'] = 'V';
    key['K'] = 'Q';
    key['L'] = 'U';
    key['M'] = 'P';
    key['N'] = 'L';
    key['O'] = 'R';
    key['P'] = 'T';
    key['Q'] = 'N';
    key['R'] = 'I';
    key['S'] = 'A';
    key['T'] = 'J';
    key['U'] = 'G';
    key['V'] = 'E';
    key['W'] = 'Z';
    key['X'] = 'W';
    key['Y'] = 'X';
    key['Z'] = 'D';
    std::cout << "text: " << mapCaesar(cipher2, key) << '\n';
  }*/

  {
    std::string cipher3 = "rs␣r␣enigm␣_aierhe␣i␣gluucsclhetersnti␣a␣rla␣t␣riayrgpetai␣diu␣Fawhiho}sipatfy␣ihr␣a␣rfa␣pes␣etohwrea␣octtonee␣eihetTpxcdeghi␣ro␣ped␣yGaledemXToneepetlhtseghectnatanst␣ripctiharaics␣foarscee␣ebrn␣te␣doemrr␣c__ltcsaicsa␣coo␣wbrn␣_aranmeibti,haarhra,sipklti␣ci.ctst␣a␣lxtcnaenlkLeoakelXpohry␣patakrntd␣cilxsU␣inehe␣cwthers␣rpo␣narahhtr␣aienlsrtrr␣o.{rd___nXnti␣_ornrtoyrgoors␣te.ksip␣_crs␣_c␣pohelhgctn␣ie␣erntatecg␣teeeAsuvesuX";
    transpositionIteration(cipher3); // iterate to six columns to solve the puzzle
  }


  /*std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i = 1;
  for (auto ch : alphabet) {
    std::cout << std::left << std::setw(3) << i++ << ": " << ch << '\n';
  }*/
}

