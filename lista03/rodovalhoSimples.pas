program aparecido;

var num1, num2, num3, soma : integer;

begin 
    read(num1);
    read(num2);
    read(num3);
    readln(soma);

    num1 := num1 + num2 + num3;

    if (soma = num1) then 
        writeln('Acertou')
    else
        writeln('Errou');
end.