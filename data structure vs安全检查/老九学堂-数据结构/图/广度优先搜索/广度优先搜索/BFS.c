
///** 广度优先搜索的核心算法 - index为广度优先搜索的某个顶点下标 */

//	void BFS_AMG(MatrixGraph G, int index) 
//	{
//		printf(" -> %s", G.verTexs[index]);
//		visited[index] = VISITED;               //设置顶点状态为已访问
//	
//		LinkedQueue queue;
//		InitLinkedQueue(&queue);				//将当前顶点入队
//		
//		OfferLinkedQueue(&queue, G.verTexs[index]);
//		while (queue.front != queue.rear) 
//		{
//			//取出队头元素，遍历队头顶点的所有邻接点
//			VerTexType vex;                     //取出的队头顶点
//			PollLinkedQueue(&queue, &vex);
//			for (int i = FirstAdjVex_AMG(G, vex); i; i = SecondAdjVex_AMG(G, vex, G.verTexs[i])) 
//			{
//				if (!visited[i]) 
//				{
//					printf(" -> %s", G.verTexs[i]);
//					visited[i] = VISITED;        //设置顶点状态为已访问
//					OfferLinkedQueue(&queue, G.verTexs[i]);
//				}
//			}
//		}
//	}

