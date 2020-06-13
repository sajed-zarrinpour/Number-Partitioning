<strong>Definition. (vertex).</strong> A vertex is a pair <img src="https://render.githubusercontent.com/render/math?math=(\phi, w)"> such that <img src="https://render.githubusercontent.com/render/math?math=\phi \in \Phi"> and <img src="https://render.githubusercontent.com/render/math?math=w \in W"> where <img src="https://render.githubusercontent.com/render/math?math=\Phi"> is a set of symbols and <img src="https://render.githubusercontent.com/render/math?math=W"> is a set of weights.

If either of the elements above were missing, we determine it by <img src="https://render.githubusercontent.com/render/math?math=\epsilon"> aad it can be ommited to symplify notations.

<strong> Remark </strong>  we call <img src="https://render.githubusercontent.com/render/math?math=(-1, \epsilon)"> a deadend.

<strong>Definition. (vertex set). </strong> A set of vertexes as defined with addition to a deadend vertex.

<strong>Definition. (job). </strong> A set of commands to accomplish a task.

<strong>Definition. (direction). </strong> A pair <img src="https://render.githubusercontent.com/render/math?math=(\psi,\delta)"> such that <img src="https://render.githubusercontent.com/render/math?math=\psi \in \Psi"> is a symbol and <img src="https://render.githubusercontent.com/render/math?math=\delta \in \Delta"> is a job as defined above.
 Note that there is one and only one unique job for each direction. We use <img src="https://render.githubusercontent.com/render/math?math=D"> to show the set of all directions.
 
 <strong> Definition. (direction function). </strong> A multicase function <img src="https://render.githubusercontent.com/render/math?math=F:V \to D"> which takes a vertex and according to the cases in it's definition will choose next direction.
 
 <strong> Definition. (edge). </strong> A triplet <img src="https://render.githubusercontent.com/render/math?math=(v, d, w)"> where <img src="https://render.githubusercontent.com/render/math?math= v \in V"> is a vertex, <img src="https://render.githubusercontent.com/render/math?math=d \in D"> is a direction and <img src="https://render.githubusercontent.com/render/math?math=w \in W_e"> is a weight. We denote the set of edges by <img src="https://render.githubusercontent.com/render/math?math=E">
 
 <strong> Definition. (Graph).</strong> We define a graph as <img src="https://render.githubusercontent.com/render/math?math=G(\Phi, \Psi, \Delta, D, E, F)">.
 
