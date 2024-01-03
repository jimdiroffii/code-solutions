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
    //std::string cipher3 = "rs_r_enigm__aierhe_i_gluucsclhetersnti_a_rla_t_riayrgpetai_diu_Fawhiho}sipatfy_ihr_a_rfa_pes_etohwrea_octtonee_eihetTpxcdeghi_ro_ped_yGaledemXToneepetlhtseghectnatanst_ripctiharaics_foarscee_ebrn_te_doemrr_c__ltcsaicsa_coo_wbrn__aranmeibti,haarhra,sipklti_ci.ctst_a_lxtcnaenlkLeoakelXpohry_patakrntd_cilxsU_inehe_cwthers_rpo_narahhtr_aienlsrtrr_o.{rd___nXnti__ornrtoyrgoors_te.ksip__crs__c_pohelhgctn_ie_erntatecg_teeeAsuvesuX";
    int lines{};
    int counter{};
    std::string line{};
    
    int currCol = 0;
    int currRow = 0;
    int rowDepth = 30;
    std::vector<std::vector<char>> transpositionArray{};

    for (auto it = cipher3.begin(); it != cipher3.end(); ++it) {
      switch (*it) {
      case 'F':
      case 'L':
      case 'A':
      case 'G':
      case '{':
      case '}':
        std::cout << "char: " << *it << " pos: " << counter << '\n';
      }

      ++counter;


      /*if (*it == '�') {
        it += 2;
        continue;
      }

      if (currCol == 0) {
        transpositionArray.push_back(std::vector<char>{*it});
      }
      else {
        transpositionArray.at(currRow).push_back(*it);
      }

      ++currRow;
      if (currRow >= rowDepth) {
        currRow = 0;
        ++currCol;
      }*/
      
      /*if ((char) *it != '_') {
        line += *it;
        ++counter;
      }

      if (counter == 6) {
        std::cout << "line: " << lines << " " << line << '\n';
        line = "";
        ++lines;
        counter = 0;
      }*/
    }

    for (std::vector v : transpositionArray) {
      for (auto ch : v) {
        std::cout << ch;
      }
      std::cout << '\n';
    }

    //std::cout << "line: " << lines << " " << line << '\n';
    //std::cout << "lines: " << lines;
  }

  /*std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i = 1;
  for (auto ch : alphabet) {
    std::cout << std::left << std::setw(3) << i++ << ": " << ch << '\n';
  }*/
}

