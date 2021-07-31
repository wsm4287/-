x: integer := 1 --- global
y: integer := 2
procedure add
 x := x + y
procedure second(P : procedure)
 x: integer := 2
 P()
procedure first
 y: integer := 3
 second(add)

	
first()
write_integer(x) 
