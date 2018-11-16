(*Exercise 1: *)

(* 1. seven: 'a -> int *)
let seven x = 7;;
 

(* 2. sign: int -> int *)
let sign x = if x < 0 then -1
else if x = 0 then 0
else 1;;


(* 3. abs: int -> int *)
let abs x = if x < 0 then -x else x;;


(* 4a. andp: bool -> bool -> bool *)
let andp x y = x && y;;

(* 4b. orp: bool -> bool -> bool *)
let orp x y = x || y;;

(* 4c. xorp: bool -> bool -> bool *)
let xorp x y = x <> y;;

(* 4d. notp: bool -> bool *)
let notp x = not x;;


(* 5. dividesby: int -> int -> bool *)
let dividesby x y = if (x mod y) = 0 then true else false;;


(* 6. is_singleton: 'a list -> bool *)
let is_singleton xs =
match xs with
	|[] -> false
	|a::[] -> true
	|a::b::c -> false;;


(* 7. swap: 'a * 'b -> 'b * 'a *)
let swap (x,y) = (y,x);;


(* 8. app: ('a -> 'b) -> 'a -> 'b *)
let app x y = x y;;


(* 9. twice: ('a -> 'a) -> 'a -> 'a *)
let twice f x = f (f x);;


(* 10. compose: ('a -> 'b) -> ('c -> 'a) -> 'c -> 'b *)
let compose x y z = x (y z);;


(*Exercise 2*)

(* Put this first so it could be used for union *)
(* 2. remAdjDups: 'a list -> 'a list *)
let rec remAdjDups = function
  | [] -> []
  | [x] -> [x]
  | x::y::xs when x=y -> remAdjDups (y::xs)
  | x::y::xs -> x::remAdjDups (y::xs);;


(* 1aa. belongsTo_ext: 'a -> 'a list -> bool *)
let rec belongsTo_ext x = function
  | [] -> false
  | y::ys -> if x=y 
  		then true
  		else belongsTo_ext x ys;;

(* 1ba. belongsTo_char: 'a -> ('a -> bool) -> bool *)
let rec belongsTo_char x = function
  | [] -> false
  | y::ys -> if x=y then true else belongsTo_char x ys;;

(* 1ab. union_ext: 'a list -> 'a list -> 'a list *)
let union_ext xs ys =
	remAdjDups(List.sort compare(xs @ ys));;

(* 1bb. union_char: ('a -> bool) -> ('a -> bool) -> ('a -> bool) *)
let union_char x y = 
	 fun res -> orp (x res) (y res);;

(* 1ac. intersection_ext: 'a list -> 'a list -> 'a list *)
(*let intersection_ext xs ys = function*)

(* 1bc. intersection_char: ('a -> bool) -> ('a -> bool) -> ('a -> bool) *)
(*let intersection_char x y = *)
  





(* 3. sublists: 'a list -> 'a list list *)
(*let rec sublists = function 
  | [] -> [[]]
  | x::xs -> let sub = sublists xs in sub @ (map (fun xs -> x::xs) sub);;*)


(*Exercise 3*)

(*type calcExp = 
  | Const of int
  | Add of (calcExp*calcExp)
  | Sub of (calcExp*calcExp)
  | Mult of (calcExp*calcExp)
  | Div of (calcExp*calcExp)

let e1 = Const(2)

let e2 = Add(Sub(Const(2), Const(3), Const(4)))


let rec mapC func exp = if Const then func (Const)
  else mapC func exp;; 

let foldC f1 f2 f3 f4 f5 e = 
	| Const -> 
	| Add -> foldC 


let replaceAddWithMult;;

let numAdd;; 

let evalC;;

let evalCf;;
*)

(*Exercise 4*)

(* 1. f: int list -> int *)
let f xs =
let g = fun x r -> if x mod 2 = 0 then (+) r 1 else r
in List.fold_right g xs 0;;
(*This function returns 2 if all of the numbers can be divided by 
 Eachother without a remainder, else it returns 1)
 (*f [5;30;120], [120;4], [2;10]  all return 2)
 ( f [5;12], [2;9], [133;34] all return 1 *)*)

(* 3. append: 'a list list -> 'a list -> 'a list *)
let append xs =
let g = fun x h -> xs @ h
in List.fold_right g xs








