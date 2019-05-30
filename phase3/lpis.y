





%%

Pai : P Nomes Eventos
    ;

Nomes : Nome
      | Nome "%" ID
      | Nome "/" Nomes
      | Nome " " Nomes
      ;

ID : Integer
   ;


Eventos :


Evento : "*" DATA
       | "+" DATA
       | "+c" DATA
       | "cc(" DATA ")" Nomes

%%
