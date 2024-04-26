//
// Created by Daniel Pantiuc on 23.04.2024.
//

#include "CosRepo.h"
#include "../exceptions/Exceptions.h"

void CosRepo::emptyCos() noexcept {
    this->Contract.clear();
}

void CosRepo::addCos(const Produs &produs) {
    this->Contract.push_back(produs);
}

void CosRepo::genereazaCos(int nr_produse, const vector<Produs> &memory) {
    emptyCos();
    auto to_cos = memory;
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    if (to_cos.size())
        while (nr_produse > 0) {
            std::shuffle(to_cos.begin(), to_cos.end(), std::default_random_engine(seed));
            for (const auto &produs : to_cos) {
                if (nr_produse == 0)
                    break;
                addCos(produs);
                nr_produse--;
            }
        }
}

const vector<Produs> &CosRepo::getCos() {
    return this->Contract;
}

void CosRepo::exportCos(const string &name_file) {
    string filename = name_file;
    auto pos = filename.find_last_of('.');
    if (pos < filename.size()) {
        auto file_extension = name_file.substr(pos);
        if (file_extension != ".html")
            filename += ".html";
    }
    else
        filename += ".html";

    std::ofstream fout(filename);
    fout << "<html>\n"
            "<body>\n"
            "<head>\n"
            "    <h3 style=\" font-family: 'Caviar Dreams',serif; color:mediumpurple; \">MAGAZIN PRODUSE</h3>\n"
            "    </head>\n"
            "<style>\n"
            "    p {\n"
            "        color: #D7BDE2 ;\n"
            "        background-color: #A9CCE3 ;\n"
            "        border: 1px solid black; }\n"
            "    table,th,td{\n"
            "        border: 1px solid black;\n"
            "    }\n"
            "    th{\n"
            "        color: darkviolet;\n"
            "    }\n"
            "    body{\n"
            "        background-color: #CACFD2;\n"
            "    }\n"
            "</style>\n";
    fout<<"<table>\n"
          "\n"
          "        <th>Nume</th>\n"
          "        <th>Tip</th>\n"
          "        <th>Pret</th>\n"
          "        <th>Producator</th>";
    for(const Produs& prds:getCos())
    {
        fout<<"<tr>\n";
        fout<<"<th>"<<prds.getNume()<<"</th>\n"
            <<"<th>"<<prds.getTip()<<"</th>\n"
            <<"<th>"<<prds.getPret()<<"</th>\n"
            <<"<th>\n"<<prds.getProducator()<<"</th>\n"
            <<"</tr>\n";
    }
    fout<<"</table>\n"
          "\n"
          "\n"
          "</body>\n"
          "</html>";
    fout.close();
}


