<strong>Definition. (vertex).</strong> A vertex is a pair $(\phi, w)$ such that $\phi \in \Phi$ and $w \in W$ where $\Phi$ is a set of symbols and $W$ is a set of weights.

If either of the elements above is missing, we determine it by $\epsilon$ and it can be omitted to simplify notations.

<strong> Remark </strong>  we call $(-1, \epsilon)$ a deadend.

<strong>Definition. (vertex set). </strong> A set of vertexes as defined with addition to the deadend vertex.

<strong>Definition. (job). </strong> A set of commands to accomplish a task.

<strong>Definition. (direction). </strong> A pair $(\psi,\delta)$ such that $\psi \in \Psi$ is a symbol and $\delta \in \Delta$ is a job as defined above.
 Note that there is one and only one unique job for each direction. We use $D$ to show the set of all directions.
 
 <strong> Definition. (direction function). </strong> A multicase function $F:V \to D$ which takes a vertex and according to the cases in it's definition will choose next direction.
 
 <strong> Definition. (edge). </strong> A triplet $(v, d, w)$ where $v \in V$ is a vertex, $d \in D$ is a direction and $w \in W_e$ is a weight. We denote the set of edges by $E$.
 
 <strong> Definition. (Graph).</strong> We define a graph as $G(\Phi, \Psi, \Delta, D, E, F)$.
 
