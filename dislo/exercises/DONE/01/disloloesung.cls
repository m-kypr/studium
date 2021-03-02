\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{disloloesung}


%%%%%%%%%% BaseClass
\LoadClass[a4paper,ngerman]{scrartcl}


%%%%%%%%%% Options
\DeclareOption{entwurf}{\AtEndOfClass{
    \RequirePackage{draftwatermark}
    \definecolor{pink}{rgb}{0.95,0.9,0.95}
    \SetWatermarkText{\textsf{\textcolor{pink}{ENTWURF}}}
    \SetWatermarkScale{1}
}}
\ProcessOptions\relax


%%%%%%%%%% Language, Layout, Typesetting and other general Packages
\RequirePackage{etex}
\RequirePackage[utf8]{inputenc}
\RequirePackage[ngerman]{babel}
\RequirePackage{lmodern}
\RequirePackage[stretch=10,shrink=10,protrusion=true,expansion=true,final]{microtype}
\RequirePackage{multicol}
\clubpenalty=10000
\widowpenalty=10000
\displaywidowpenalty=10000


%%%%%%%%%% Information Commands
\RequirePackage{xparse}
\NewDocumentCommand{\name}{m}{\newcommand{\@name}{#1}}
\NewDocumentCommand{\semester}{m}{\newcommand{\@semester}{#1}}
\NewDocumentCommand{\class}{m}{\newcommand{\@class}{#1}}
\NewDocumentCommand{\tutor}{m}{\newcommand{\@tutor}{#1}}
\NewDocumentCommand{\uebung}{m}{\newcommand{\@uebung}{#1}}

%%%%%%%%%% Lengths
\newlength{\titleskip}
\setlength{\titleskip}{1.5em}
\newlength{\aufgabenskip}
\setlength{\aufgabenskip}{1.5em}



%%%%%%%%%% Page styles
% paper: Neues, eigenstaendiges Dokument
\newenvironment{paper}{%
    \pagestyle{empty}%
    \begin{center}
        \begin{minipage}{0.5\textwidth}
            \@name 
        \end{minipage}
        \hfill
        \begin{minipage}{0.45\textwidth}
            \begin{flushright}
                \textbf{\@class}\\ 
                Ü\@uebung\hspace{2mm} (\@tutor)\\
                \@semester
            \end{flushright}
        \end{minipage}
    \end{center}
}{\newpage}
% paperwt: paper mit Titel und Untertitel
\newenvironment{paperwt}[1]{\begin{paper}
    \begin{center}
    \Large \textbf{#1}
    \end{center}
    \vspace{\titleskip}}{\end{paper}}
    % sheet: Neues Blatt mit Loesungen
    \newenvironment{sheet}[1]{\begin{paperwt}{L\"osungen zu Blatt #1}}{\end{paperwt}}


    %%%%%%%%%%% Enumeratestyles (a),(b),... with proper reference styles
    \renewcommand*\theenumi{\alph{enumi}}
    \renewcommand*\theenumii{\arabic{enumii}}
    \renewcommand{\labelenumi}{(\theenumi)}
    \renewcommand{\labelenumii}{\theenumii.}


    %%%%%%%%%%% Loesungen
    % aufgabe: Eine Aufgabe
    \newenvironment{aufgabe}[2]{
        \noindent\textbf{Aufgabe #1.} \emph{#2} \par
    }{\par\vspace{\aufgabenskip}}
% aufgabe*: Eine *-Aufgabe
\newenvironment{aufgabe*}[2]{
    \noindent\textbf{Aufgabe* #1.} \emph{#2} \par
}{\vspace{\aufgabenskip}}
