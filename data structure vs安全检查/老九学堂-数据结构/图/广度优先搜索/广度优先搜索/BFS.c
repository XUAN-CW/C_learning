
///** ������������ĺ����㷨 - indexΪ�������������ĳ�������±� */

//	void BFS_AMG(MatrixGraph G, int index) 
//	{
//		printf(" -> %s", G.verTexs[index]);
//		visited[index] = VISITED;               //���ö���״̬Ϊ�ѷ���
//	
//		LinkedQueue queue;
//		InitLinkedQueue(&queue);				//����ǰ�������
//		
//		OfferLinkedQueue(&queue, G.verTexs[index]);
//		while (queue.front != queue.rear) 
//		{
//			//ȡ����ͷԪ�أ�������ͷ����������ڽӵ�
//			VerTexType vex;                     //ȡ���Ķ�ͷ����
//			PollLinkedQueue(&queue, &vex);
//			for (int i = FirstAdjVex_AMG(G, vex); i; i = SecondAdjVex_AMG(G, vex, G.verTexs[i])) 
//			{
//				if (!visited[i]) 
//				{
//					printf(" -> %s", G.verTexs[i]);
//					visited[i] = VISITED;        //���ö���״̬Ϊ�ѷ���
//					OfferLinkedQueue(&queue, G.verTexs[i]);
//				}
//			}
//		}
//	}

