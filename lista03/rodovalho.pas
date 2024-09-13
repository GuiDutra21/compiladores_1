program rodovalho;

var 
    i, numero, soma, resposta : longint;
begin
    soma := 0;
    
    readln(i);

    while (i > 0) do
    begin
        read(numero);
        soma := soma + numero;
        i := i - 1;
    end;

    readln(resposta);

    if(resposta = soma) then
        writeln('Acertou')
    else
        writeln('Errou');
end.
