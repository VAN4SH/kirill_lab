Windows Forms (C++/CLI) — kak v metodichke po Visual Studio
============================================================

Gde lezhit
----------
Papka: kirill_lab/winforms_cppcli/
  KirillLabsWin.sln          — otkryt' v Visual Studio na Windows
  include/MathVariant25.h    — obshhie formuly variant 25
  Lab03Win ... Lab09Win      — otdel'nye proekty (bez Lab07 — tam Monte Carlo, mozhno dobavit' po analogii)

Vazhno
------
1) Jeti proekty sobirajutsja TOL'KO v Microsoft Visual Studio pod Windows (CLR / .NET Framework).
   Na Linux v Cursor/WSL graficheskij Windows Forms ne zapuskaetsja — konsol'nye lab*.cpp v kirill_lab ostalis' dlja proverki logiki.

2) Nuzhny komponenty:
   — Rabochaja nagruzka «Razrabotka klassicheskih prilozhenij na C++» (MSVC)
   — Podderzhka C++/CLI (v ustano VS vklyuchaetsja v komponentah)

3) Platforma v reshenii: x64. Esli net v143, otkrojte svojstvo proekta → obshhie → nabor instrumentov platformy (v142 i t.d.).

4) Lab04 i Lab08 ssylajutsja na System.Windows.Forms.DataVisualization (Chart).
   Esli pri sborke ne nahodit DLL: svojstvo proekta → ssylki → dobavit' ssylku na
   System.Windows.Forms.DataVisualization (iz GAC / .NET Framework 4.x).

5) Lab08 — uproshhennoe menju «Fajl → Vyhod» i tri vkladki. Polnoe menju ColorDialog/FontDialog/SaveFileDialog kak v metodichke mozhno dobavit' cherez dizajner VS.

Sborка
------
Otkryt' KirillLabsWin.sln → pravyj knopka na nuzhnoj laboratornoj → «Nachat' otlazhku» ili Ctrl+F5.

Sootvetstvie s konsol'ju
----------------------
Logika chisel sovpadaet s fajlami lab03.cpp … lab09.cpp v roditel'skoj papke kirill_lab.
