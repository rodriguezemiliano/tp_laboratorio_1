/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"



int main(void)
{
        startTesting(1);//newArraylist
        startTesting(2);//add
        startTesting(3);//deleteArrayList
        startTesting(4);//len
        startTesting(5);//get
        startTesting(6);//contain
        startTesting(7);//set
        startTesting(8);//remove
        startTesting(9);//clear
        startTesting(10);//clone
        startTesting(11);//push
        startTesting(12);//indexOf
        startTesting(13);//isImpty
        startTesting(14);//pop
        startTesting(15);//subList
        startTesting(16);//contaisAll
        startTesting(17);//sort

    return 0;
}





