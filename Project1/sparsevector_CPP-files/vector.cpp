#include "vector.h"
#include <stdio.h>
#include <stdlib.h>



namespace CS225
{

	SparseVector operator*(int t, SparseVector& v)
	{
		return v*t;
	}


	SparseVector operator*(int t, const SparseVector& v)
	{
		return v*t;
	}











	ElementProxy operator*(int t, ElementProxy& p)
	{
		return p*t;
	}

	SparseVector::~SparseVector()
	{
		//printf("Calling destructor\n", this->getHead());
		if (pHead != NULL)
		{

			ElementNode * current = pHead;
			ElementNode * next = (*pHead).next;

			while (current)
			{
				delete(current);
				current = next;
				if (next)
				{
					next = next->next;
				}
			}
		}

	}




	/* this is the only place where dimension is used */
	std::ostream& operator<<(std::ostream &out, const SparseVector &v) {
		int i, last_pos = -1;
		ElementNode* p_e = v.getHead();
		while (p_e) {
			for (i = last_pos + 1; i<p_e->pos; ++i) out << " " << "0";
			out << " " << p_e->data;
			last_pos = p_e->pos;
			p_e = p_e->next;
		}
		for (i = last_pos + 1; i<v.getDimension(); ++i) out << " " << "0";

		return out;
	}



	//


	//void delete_element(ElementNode ** p_e, int pos)
	//{
	//	insert_element(p_e, pos, 0);
	//}

	//
	//void delete_element(ElementNode * * p_e, int pos)
	//{
	//
	//	
	//
	//	ElementNode * prev = *p_e;
	//	ElementNode * current = (prev)->next;
	//
	//	if (prev->pos == pos)
	//	{
	//		delete(prev);
	//		(*p_e) = current;
	//	}
	//
	//
	//	do
	//	{
	//
	//		if (current->pos == pos)
	//		{
	//			/* If we're deleting the head node, delete *p_e and point the head to the next node */
	//
	//			prev->next = current->next;
	//			delete(current);
	//
	//		}
	//
	//		else if (current->pos > pos)
	//		{
	//			current = NULL;
	//			/* No position corresponding to input, nothing to delete. */
	//		}
	//
	//		else
	//		{
	//
	//			prev = current;
	//			if (current != NULL)
	//			{
	//				current = current->next;
	//			}
	//		}
	//
	//	} while (current != NULL);
	//
	//
	//}

	//int get(ElementNode const * p_e, int pos)
	//{

	//	const ElementNode * n = p_e;


	//	do {
	//		if (n->pos == pos)
	//		{
	//			return n->data;
	//		}

	//		else
	//		{
	//			/* printf("Current position & data check:  %i, %i\n", n->pos, n->data);*/

	//			if (n->pos > pos)
	//			{
	//				n = NULL;
	//			}
	//			else
	//			{
	//				n = n->next;
	//			}

	//		}
	//	} while (n != NULL);





	//	return 0;










	//}

	//int scalar_product(ElementNode const * p_e1, ElementNode const * p_e2)
	//{
	//	int temp = 0;

	//	const ElementNode * current1 = p_e1;
	//	const ElementNode * current2 = p_e2;


	//	while (current1 != NULL && current2 != NULL)
	//	{
	//		if (current1->pos > current2->pos)
	//		{
	//			current2 = current2->next;
	//		}

	//		else if (current1->pos < current2->pos)
	//		{
	//			current1 = current1->next;
	//		}

	//		else
	//		{
	//			temp = temp + (current1->data * current2->data);
	//			current1 = current1->next;

	//		}
	//	}

	//	return temp;



	//}


	//ElementNode * add(ElementNode const * p_e1, ElementNode const * p_e2)
	//{

	//	ElementNode * temp = NULL;


	//	const ElementNode * current1 = p_e1;
	//	const ElementNode * current2 = p_e2;

	//	int holder = 0;

	//	int i = 0;



	//	while (current1 != NULL || current2 != NULL)
	//	{
	//		/* printf("Inserting element %i into new vector.\n", i);*/
	//		/*
	//		printf("Current loop:  %i\n", i);
	//		printf("Current positions in curr1, cur2:  (%i, %i)\n", current1->pos, current2->pos);

	//		*/     holder = get(p_e1, i) + get(p_e2, i);

	//		/*  printf("a+b = holder:  %i + %i = %i", a, b, holder);
	//		printf("Holder value assigned:  %i\n", holder);*/

	//	if (holder != 0)
	//	{
	//		/*
	//		if (temp == NULL)
	//		{
	//		temp = 0;
	//		}
	//		*/
	//		insert_element(&temp, i, holder);
	//	}



	//	if (current1 != NULL  &&  i == current1->pos)
	//	{

	//		current1 = current1->next;


	//	}

	//	if (current2 != NULL && i == current2->pos)
	//	{

	//		current2 = current2->next;

	//	}


	//	i++;


	//	}
	//	/*
	//	if(temp==NULL)
	//	{
	//	printf("Temp is null like it should be.\n");
	//	}*/

	//	if (temp == NULL)
	//	{
	//		free(temp);
	//		return NULL;
	//	}
	//	else
	//	{
	//		return temp;

	//	}
	//}

	//void free_elements(ElementNode * p_e)
	//{
	//	if (p_e != NULL)
	//	{

	//		ElementNode * current = p_e;
	//		ElementNode * next = (*p_e).next;

	//		while (current != NULL)
	//		{
	//			delete(current);
	//			current = next;
	//			if (next != NULL)
	//			{
	//				next = next->next;
	//			}
	//		}
	//	}
	//}




	void SparseVector::Insert(int val, long pos)
	{


		if (pos >= this->getDimension())
		{
			this->setDimension(pos + 1);
		}// automatically set dimension (it effects operator<< only)



	
			ElementNode * current = this->getHead();
			ElementNode * next = NULL;
			if (current != NULL)
			{
				next = current->next;
			}

			else
			{
				if (val != 0)
				{
					ElementNode * nodeToInsert = new ElementNode;
					if (nodeToInsert == NULL)
					{
						return;
					}
					nodeToInsert->data = val;
					nodeToInsert->pos = pos;
					nodeToInsert->next = NULL;
					this->setHead(nodeToInsert);
				}
				return;
			}

			if (val == 0)
			{

				if (current->pos == pos)
				{
					this->setHead(next);
					delete(current);
				}
				else {
					while(next!=NULL)
					{
						if (next->pos == pos)
						{
							if (next != NULL)
							{
								current->next = next->next;
							}

							else
							{
								current->next = NULL;
							}

							delete(next);
							break;
						}

						current = next;
						if (next != NULL)
						{
							next = next->next;
						}

					}
				}
				return;
			}

			else
			{
				ElementNode * nodeToInsert = new ElementNode;
				if (nodeToInsert == NULL)
				{
					return;
				}
				nodeToInsert->data = val;
				nodeToInsert->pos = pos;
				nodeToInsert->next = NULL;
				if (pos < current->pos)
				{
					this->setHead(nodeToInsert);
					
					nodeToInsert->next = current;


				}

				else if (pos == current->pos)
				{
					delete(nodeToInsert);
					current->data = val;
				}

				else {
					do
					{
						if (current->pos < pos && next == NULL)
						{
							current->next = nodeToInsert;
						}
						if (next != NULL)
						{
							if (pos < next->pos)
							{
								current->next = nodeToInsert;
								nodeToInsert->next = next;
								break;
							}

							else if (pos == next->pos)
							{
								delete(nodeToInsert);
								next->data = val;
								break;
							}
						}
						current = next;
						if (next != NULL)
						{
							next = next->next;
						}

					} while (current != NULL);
				}
				return;

			}


			//if (*p_e == NULL)
			//{
			//	*p_e = new ElementNode;

			//	if (*p_e == NULL)  //If I malloc and it's STILL NULL, malloc failed, return 1
			//	{
			//		return 1;
			//	}

			//	(*p_e)->data = val;
			//	(*p_e)->pos = pos;
			//	(*p_e)->next = NULL;
			//	return 0;
			//}
			//else
			//{
			//	ElementNode * current = *p_e;
			//	ElementNode * next = (*p_e)->next;
			//	ElementNode * nodeToInsert = NULL;
			//	if (val != 0)
			//	{
			//		nodeToInsert = new ElementNode;

			//		if (nodeToInsert == NULL)
			//		{
			//			return 1;
			//		}

			//		else {
			//			nodeToInsert->data = val;
			//			nodeToInsert->pos = pos;
			//			nodeToInsert->next = NULL;

			//		}

			//	}

			//	//Check if next==NULL
			//	if (next == NULL)
			//	{
			//		if (val != 0)
			//		{
			//			if (pos < current->pos)  //Node to insert comes before first node in vector, node to insert is new head of vector
			//			{
			//				nodeToInsert->next = (*p_e);
			//				p_e = &nodeToInsert;




			//			}

			//			else if (pos == current->pos)  //Simple replacement, don't need to use the new node we created
			//			{
			//				(*p_e)->data = val;


			//			}

			//			else  //New node comes after current head of vector
			//			{
			//				(*p_e)->next = nodeToInsert;


			//			}


			//		}

			//		else
			//		{
			//			if (pos = current->pos)
			//			{
			//				delete(*p_e);
			//				*p_e = NULL;
			//			}
			//		}
			//		/*
			//		current = NULL;
			//		delete(current);
			//		next = NULL;
			//		delete(next);
			//		nodeToInsert = NULL;
			//		delete(nodeToInsert);  //Double check these lines?

			//		return 0;
			//		*/
			//	}
			//	else
			//	{
			//		if (val != 0)
			//		{
			//			do
			//			{
			//				if (pos < current->pos)  //Similar to above
			//				{
			//					nodeToInsert->next = (*p_e);
			//					p_e = &nodeToInsert;
			//				}

			//				else if (pos == current->pos)
			//				{
			//					(*p_e)->data = val;
			//				}

			//				else if (next != NULL && pos < next->pos)
			//				{
			//					current->next = nodeToInsert;
			//					nodeToInsert->next = next;
			//				}

			//				else if (next == NULL)
			//				{
			//					current->next = nodeToInsert;
			//				}

			//				
			//					current = next;
			//					if (next != NULL)
			//					{
			//						next = next->next;
			//					}
			//				


			//			} while (current != NULL);

			//		}

			//		else
			//		{
			//			delete(nodeToInsert);
			//			nodeToInsert = NULL;
			//			do {
			//				if (pos == next->pos)
			//				{
			//					current->next = next->next;
			//					delete(next);
			//				}

			//				current = next;
			//				if (next != NULL)
			//				{
			//					next = next->next;
			//				}


			//			} while (next != NULL);
			//		}


			//	}

			//	current = NULL;

			//	next = NULL;

			//	nodeToInsert = NULL;
			//	//Double check these lines?




			//}

			//return 0;

		}




	


	int SparseVector::Get(long pos) const
	{
		const ElementNode * n = this->getHead();
		if (n == NULL)
		{
			return 0;
		}

		do {
			if (n->pos == pos)
			{
				return n->data;
			}

			else
			{

				if (n->pos > pos)
				{
					n = NULL;
				}
				else
				{
					n = n->next;
				}
			}
		} while (n != NULL);
		n = NULL;
		return 0;
	}

	int SparseVector::operator[](long pos) const
	{
		return this->Get(pos);
	}



	void SparseVector::Delete(long pos)
	{



		ElementNode * prev = this->getHead();
		if (prev == NULL)
		{
			return;
		}
		ElementNode * current = (prev)->next;



		if (prev->pos == pos)
		{
			delete(prev);
			if (current != NULL)
			{
				this->setHead(current);
			}

			else
			{
				this->setHead(NULL);
			}
			return;
		}


		do
		{
			if (current == NULL)
			{
				return;
			}
			if (current->pos == pos)
			{
				/* If we're deleting the head node, delete *p_e and point the head to the next node */

				prev->next = current->next;
				delete(current);

			}

			else if (current->pos > pos)
			{
				current = NULL;
				/* No position corresponding to input, nothing to delete. */
			}

			else
			{

				prev = current;
				if (current != NULL)
				{
					current = current->next;
				}
			}

		} while (current != NULL);

		current = NULL;
		prev = NULL;


	}

	ElementNode* SparseVector::getHead() const
	{
		return pHead;
	}



	long SparseVector::getDimension() const
	{

		return dimension;


	}

	void SparseVector::setHead(ElementNode* p)
	{
		pHead = p;
	}

	void SparseVector::setDimension(long x)
	{
		dimension = x;
	}

	long ElementProxy::getPos() const
	{
		return this->pos;
	}

	SparseVector& ElementProxy::getVector() const
	{
		return this->v;
	}

	void ElementProxy::setPos(long pos)
	{
		this->pos = pos;
	}

	void ElementProxy::setVector(SparseVector& v)
	{
		this->v = v;
	}




	const ElementProxy SparseVector::operator[](long pos)
	{
		ElementProxy t = ElementProxy(*this, pos);

		return t;

	}


	SparseVector SparseVector::operator+(const SparseVector& v)
	{
		SparseVector temp;

		const ElementNode * current1 = this->getHead();
		const ElementNode * current2 = v.getHead();

		int holder = 0;
		int i = 0;




		while (current1 != NULL || current2 != NULL)
		{


			holder = this->Get(i) + v.Get(i);



			if (holder != 0)
			{

				temp.Insert(holder, i);
			}



			if (current1 != NULL  &&  i == current1->pos)
			{

				current1 = current1->next;


			}

			if (current2 != NULL && i == current2->pos)
			{

				current2 = current2->next;

			}


			i++;


		}
		current1 = NULL;
		current2 = NULL;

		return temp;


	}


	SparseVector SparseVector::operator*(const int t)
	{
		SparseVector v(*this);
		v.setDimension(this->getDimension());
		//printf("Head of this, v, are:  %s, %s\n", v.getHead(), this->getHead());

		ElementNode * x = v.getHead();
		ElementNode* y = NULL;
		if(x)
		{
			y = x->next;
		}

		while (x)
		{
			if (t != 0)
			{
				x->data = x->data*t;
				x = x->next;
			}
			else
			{
				///x = x->next;
				if (x != NULL)
				{
					v.Delete(x->pos);
				}
				//v.setHead(NULL);
				x = y;
				if(y)
				{
					y = y->next;
				}
			}
		}
		// x=NULL;
		v.setDimension(this->getDimension());
		return v;
	}


	SparseVector SparseVector::operator*(const int t) const
	{
		SparseVector v(*this);
		v.setDimension(this->getDimension());
		ElementNode * x = v.getHead();
		ElementNode* y = NULL;
		if (x)
		{
			y = x->next;
		}

		while (x)
		{
			if (t != 0)
			{
				x->data = x->data*t;
				x = x->next;
			}
			else
			{
				
				if (x != NULL)
				{
					v.Delete(x->pos);
				}
				//v.setHead(NULL);
				x = y;
				if (y)
				{
					y = y->next;
				}
			}
		}
	//	x = NULL;
		v.setDimension(this->getDimension());
		return v;
	}



	const SparseVector& SparseVector::operator=(const SparseVector& v1)
	{
		//printf("Calling assignment operator\n");
		if (this->getHead() == NULL)
		{
			SparseVector v = SparseVector();
			*this = v;
		}
		ElementNode * inputStart = v1.getHead();

		/*while (this->getHead())
		{
		Delete(this->getHead()->pos);
		}
		*/


		while (inputStart)
		{
			this->Insert(inputStart->data, inputStart->pos);
			inputStart = inputStart->next;
		}



		/*

		while (thisStart || inputStart)
		{
		if()

		if(inputStart->pos > thisStart->pos)
		{
		this->Delete( thisStart->pos);
		thisStart = thisStart->next;
		}

		else
		{
		if (inputStart->data != 0)
		{
		this->Insert(inputStart->data, inputStart->pos);
		}
		inputStart = inputStart->next;
		}

		}
		*/
		//if it broke because thisStart == NULL, continue inserting until inputStart == NULL
		//if it broke because inputStart==NULL, zero out everything else in this
		inputStart = NULL;


		return *this;

	}





	int SparseVector::operator*(const SparseVector& v1) const
	{
		int temp = 0;

		const ElementNode * current1 = this->getHead();
		const ElementNode * current2 = v1.getHead();


		while (current1 != NULL && current2 != NULL)
		{
			if (current1->pos > current2->pos)
			{
				current2 = current2->next;
			}

			else if (current1->pos < current2->pos)
			{
				current1 = current1->next;
			}

			else
			{
				temp = temp + (current1->data * current2->data);
				current1 = current1->next;

			}
		}

		current1 = NULL;
		current2 = NULL;
		delete(current1);
		delete(current2);
		return temp;



	}



	SparseVector SparseVector::operator+=(const SparseVector& v)
	{

		//SparseVector temp;

		const ElementNode * current1 = this->getHead();
		const ElementNode * current2 = v.getHead();

		int holder = 0;
		int i = 0;


		/*
		while(current1 !=NULL && current2!=NULL)
		{

		if(current1->pos > current2->pos)
		{

		current2=current2->next;
		}

		else if(current1->pos < current2->pos)
		{
		current1=current1->next;
		}

		else
		{
		insert_element(&temp, current1->pos, (current1->data + current2->data));
		current1=current1->next;

		}
		}*/

		while (current1 != NULL || current2 != NULL)
		{
			/* printf("Inserting element %i into new vector.\n", i);*/
			/*
			printf("Current loop:  %i\n", i);
			printf("Current positions in curr1, cur2:  (%i, %i)\n", current1->pos, current2->pos);

			*/     holder = this->Get(i) + v.Get(i);

			/*  printf("a+b = holder:  %i + %i = %i", a, b, holder);
			printf("Holder value assigned:  %i\n", holder);*/

		if (holder != 0)
		{

			this->Insert(holder, i);
		}



		if (current1 != NULL  &&  i == current1->pos)
		{

			current1 = current1->next;


		}

		if (current2 != NULL && i == current2->pos)
		{

			current2 = current2->next;

		}


		i++;


		}
		current1 = NULL;
		current2 = NULL;

		return *this;

	}


	SparseVector SparseVector::operator-=(const SparseVector& v)
	{
		//SparseVector temp;

		const ElementNode * current1 = this->getHead();
		const ElementNode * current2 = v.getHead();

		int holder = 0;
		int i = 0;


		/*
		while(current1 !=NULL && current2!=NULL)
		{

		if(current1->pos > current2->pos)
		{

		current2=current2->next;
		}

		else if(current1->pos < current2->pos)
		{
		current1=current1->next;
		}

		else
		{
		insert_element(&temp, current1->pos, (current1->data + current2->data));
		current1=current1->next;

		}
		}*/

		while (current1 != NULL || current2 != NULL)
		{
			/* printf("Inserting element %i into new vector.\n", i);*/
			/*
			printf("Current loop:  %i\n", i);
			printf("Current positions in curr1, cur2:  (%i, %i)\n", current1->pos, current2->pos);

			*/     holder = this->Get(i) - v.Get(i);

			/*  printf("a+b = holder:  %i + %i = %i", a, b, holder);
			printf("Holder value assigned:  %i\n", holder);*/

		if (holder != 0)
		{

			this->Insert(holder, i);
		}



		if (current1 != NULL  &&  i == current1->pos)
		{

			current1 = current1->next;


		}

		if (current2 != NULL && i == current2->pos)
		{

			current2 = current2->next;

		}


		i++;


		}
		current1 = NULL;
		current2 = NULL;

		return *this;
	}


	SparseVector SparseVector::operator-(const SparseVector& v)
	{
		SparseVector temp;

		const ElementNode * current1 = this->getHead();
		const ElementNode * current2 = v.getHead();

		int holder = 0;
		int i = 0;


		/*
		while(current1 !=NULL && current2!=NULL)
		{

		if(current1->pos > current2->pos)
		{

		current2=current2->next;
		}

		else if(current1->pos < current2->pos)
		{
		current1=current1->next;
		}

		else
		{
		insert_element(&temp, current1->pos, (current1->data + current2->data));
		current1=current1->next;

		}
		}*/

		while (current1 != NULL || current2 != NULL)
		{
			/* printf("Inserting element %i into new vector.\n", i);*/
			/*
			printf("Current loop:  %i\n", i);
			printf("Current positions in curr1, cur2:  (%i, %i)\n", current1->pos, current2->pos);

			*/     holder = this->Get(i) + v.Get(i);

			/*  printf("a+b = holder:  %i + %i = %i", a, b, holder);
			printf("Holder value assigned:  %i\n", holder);*/

		if (holder != 0)
		{

			temp.Insert(holder, i);
		}



		if (current1 != NULL  &&  i == current1->pos)
		{

			current1 = current1->next;


		}

		if (current2 != NULL && i == current2->pos)
		{

			current2 = current2->next;

		}


		i++;


		}
		current1 = NULL;
		current2 = NULL;

		return temp;
	}


}

