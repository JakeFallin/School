-module(basic).
-export([mult/2]).
-export([double/1]).
-export([distance/2]).
-export([my_and/2]).
-export([my_or/2]).
-export([my_not/1]).
-export([fib/1]).
-export([tail_recursive_fib/1]).
% -export([max/1]).
-export([sum/1]).
-export([reverse/1]).

mult(A,B) ->
	A * B.

double(A) ->
	float(A).

distance(A,B) ->
	abs(A-B).

my_and(A,B) ->
	A band B.

my_or(A,B) ->
	A bor B.

my_not(A) ->
	bnot A.

fib(1) -> 1;
fib(2) -> 1;
fib(N) ->
	fib(N-1) + fib(N-2).

tail_recursive_fib(N) ->
    tail_recursive_fib(N, 0, 1, []).
tail_recursive_fib(0, _Current, _Next, Fibs) ->
    lists:reverse(Fibs);
tail_recursive_fib(N, Current, Next, Fibs) -> 
    tail_recursive_fib(N - 1, Next, Current + Next, [Current|Fibs]).


% max(L) -> max(L, 0).
% max([H|T], T) ->
%     if(H>T) max(T, H);
% max([], L) -> T.


sum(L) -> sum(L,0).
sum([H|T], Sum) -> sum(T, Sum + H);
sum([], Sum) -> Sum.

reverse(L) -> 
	lists:reverse(L).