# Cvičení 11 - Problém batohu, generování podmnožin

## Zadání cvičení:
- Ve vstupním souboru je na prvním řádku číslo n - kapacita batohu. 
- Na následujících řádcích se nachází trojice čísel, reprezentující po řadě:
  - Číslo předmětu 
  - Hmotnost předmětu 
  - Cenu předmětu
- V šabloně máte již vytvořenou strukturu Item pro uložení načtených hodnot a připravené čtení ze souboru a uložení předmětů do vektoru struktur.
- V šabloně se taktéž nachází funkce subsets, která pro vstupní vektor struktur Item vygeneruje všechny jeho podmnožiny.
- Váš úkol je jednoduchý, nalézt optimální řešení pro danou instanci problému batohu.
  - Zavolejte funkci subsets, a pro každou výslednou podmnožinu předmětů vypočítejte celkovou hmotnost a cenu.
  - Nalezněte podmnožinu s maximální cenou, avšak nepřesahující kapacitu batohu.