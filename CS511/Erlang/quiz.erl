-module(quiz).
--export ([isComplete/1]).
--export ([inorder/2]).



%isComplete( , ( )) -> ok;
%queue.in(L)
%isComplete(F, (node,V,L,R )) ->
%    // if (isEmpty(L) and isEmpty(R))
%    // queue.out()
%    // if (!isEmpty(L) and !isEmpty(R))
%    // then break
%	 //
%    // else complete = false
%		
%    // if complete == true t
%    // then return true
%    // else return false\




%BFS using queue, loop till queue is not null and break when either
%1. Left node is not present
%2. Left node is present but right node is not present

%not at all complete or finished
%understand the concept but not the syntax of erlang


isComplete({}) -> 
	true;

isComplete(T) ->
	Q = queue:new();
	isComplete(_,T);
	
isComplete(_,T) -> 
	Q = queue:in(L);
	isComplete(L);
	Q = queue:in(R);
	isComplete(R),
	if
		L == {} and R == {} ->
			queue:out();
	end;
	if
		queue:isEmpty() -> 
			false;
	end.
	true.



