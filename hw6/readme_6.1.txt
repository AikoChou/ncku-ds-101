[�{���[�c]

Global variable
-Array heap[200]
-n: heap��node���`�Ӽ�

�@�B�D�{��

�ŧi�ܼ�
Ū���ɮ�

/*Create Max Heap*/
�̧�fscanf value
�éI�spushHeap�Ƶ{��

�I�sprintHeap�Ƶ{���L�XMax Heap

while�j��: �����߰ݬO�_�nChange priority?

	if 'Y': �VUser���ooldPriority��newPriority
		������o�w�餺���p�ɾ�����(BeginTime)
		for loop ���oldPriority�Ҧb��m
			 �ç令newPriority
		/*Max Heapify*/
		while loop �q�o��node�I�smax_heapify�Ƶ{��
			   �Υ���parent node����root
  			   (�]max_heapify�u�T�O�H��node�H�U��max heap)	
		������o�w�餺���p�ɾ�����(EndTime)
		�I�sprintHeap�Ƶ{���L�XMax Heap
		�p��Spend time�æL�X
				
	if 'N': ���N�䵲���{��


�G�BpushHeap �Ƶ{��
parameter�O�n�[�Jheap��item
�O�ܼ�i�O�̫�@�Ӫ���m
���ˬdheap�O�_���F
while loop ���item�O�_�񥦪�parent�j
�Y�j��h��parent��child����m
�ܼ�i��אּparent��index�A�M����grandparent���
�̦���������root
�Y���j��h���Xloop ������m��Jitem����
�̫�C�[�J�@��node�hn�ȥ[1

�T�BprintHeap �Ƶ{��
�̧ǦL�Xnode

�|�Bmax_heapify �Ƶ{��
parameter�O��ʹLPriority��index
�O����left child��index��l
      right child��index��r
�����Priority�M�������k�Ĥl ��X�̤j��
�Y�̤j�ȬO�X�{�b�Ĥl�N�洫��m
  �A�I�s����(Recursion) 
  parameter��אּ�X�{�̤j�Ȫ�index
�p���i�H�T�O�HnewPriority��root��max heap

[�{���y��]

C

[�sĶ����]

Dev-C++ 4.9.9.2

[�{���ާ@��k]

Input Yes(Y) or No(N)

Input old priority and new priority

[�B�~�\��] 

�L