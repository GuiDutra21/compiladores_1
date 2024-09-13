program temperatura;

var
    escala1, escala2 : char;
    temp : real;

begin
    readln(escala1);
    readln(escala2);
    readln(temp);

    if (escala1 = 'C') and (escala2 = 'F') then
        temp := temp * 1.8 + 32
    else
        if(escala1 = 'C') and (escala2 = 'K') then
            temp := temp + 273.15
        else
            if(escala1 = 'K') and (escala2 = 'C') then
                temp := temp - 273.15
            else
                if(escala1 = 'K') and (escala2 = 'F') then
                    temp := ((temp * 9 - 2458.35)/5) + 32
                else
                    if(escala1 = 'F') and (escala2 = 'C') then
                        temp := (temp - 32.0)/1.8
                    else
                        temp := ((temp * 5 - 160)/9) + 273.15;
    writeln(temp:0:2);
end.