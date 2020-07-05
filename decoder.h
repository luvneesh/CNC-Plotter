


int decoder(char line[])

{   
    if (line[0]=='M'){
        if (line[1]=='0' && line[2]=='3'){
            return 1;       //pendown

        }
        if (line[1]=='0' && line[2]=='5'){
            return 2;       //penup

        }
        if (line[1]=='7' && line[2]=='1'){
            return -2;       //metric untis

        }
        if (line[1]=='3' && line[2]=='0'){
            return 0;       //EOF

        }
        else 
            return -1;
    }
    if (line[0]=='G'){
        if (line[1]=='3' && line[2]=='1'){
            return -3;       //incremental approach

        }
        if (line[1]=='0' && line[2]=='1'){
            return 3;       //linear interpolation

        }
        else 
            return -1;

    }
    else 
        return -1;
|}