program somaN;

var 
    i, numero : longint;
    soma : longint;
begin
    soma := 0;
    
    readln(i);

    while (i > 0) do
    begin
        readln(numero);
        soma := soma + numero;
        i := i - 1;
    end;
    writeln(soma);
end.