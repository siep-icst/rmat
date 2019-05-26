#include "../util/Util.h"

typedef boost::adjacency_list<> Graph;
typedef boost::rmat_iterator<boost::minstd_rand, Graph> RMATGen;
// typedef boost::graph_traits<Graph>::vertices_size_type size_type;

int main(int argc, const char* argv[])
{

  if(argc!=7)
  {
    printf("invalid arguments\n");
    return 0;
  }
  boost::minstd_rand gen;

  //parameters
  int v_num=100;
  int e_num=400;
  int A=57,B=19,C=19,D=5;

  v_num=atoi(argv[1]);
  e_num=atoi(argv[2]);
  A=atoi(argv[3]);
  B=atoi(argv[4]);
  C=atoi(argv[5]);
  D=atoi(argv[6]);

  double a=(double)A/100;
  double b=(double)B/100;
  double c=(double)C/100;
  double d=(double)D/100;

  printf("a=%lf b=%lf c=%lf d=%lf\n",a,b,c,d);
  char* file_name=(char*)malloc(100*sizeof(char));
  sprintf(file_name,"rmat_v%d_e%d_%d_%d_%d_%d.txt",v_num,e_num,A,B,C,D);
  printf("write to file: %s\n",file_name);
  FILE* ofp=fopen(file_name,"w+");

  Graph g(RMATGen(gen,v_num, e_num, a, b, c, d), RMATGen(), 100);
  //print all vertex
  // std::cout<<"print all vertices:"<<std::endl;
  boost::graph_traits<Graph>::vertex_iterator vi, vi_end;
  for(boost::tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi)
  {
    int tmp_v=*vi;
    fprintf(ofp,"v %d\n",tmp_v);
  }
  // std::cout<<"print all edges:"<<std::endl;
  boost::graph_traits<Graph>::edge_iterator ei, ei_end;
  for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
  {
    int v_left=source(*ei, g);
    int v_right=target(*ei, g);
    fprintf(ofp,"e %d %d\n",v_left,v_right);
  }


  //print adjacency vertices of a vertex u
  // std::cout<<"print adjacency vertices of a vertex u"<<std::endl;

  // size_type u=1;
  // boost::graph_traits<Graph>::adjacency_iterator vi, vi_end;
  //   for(boost::tie(vi, vi_end) = adjacent_vertices(u, g); vi != vi_end; ++vi)
  //       std::cout<<*vi<<std::endl;

  return 0;
}