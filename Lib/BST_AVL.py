class Node :
    def __init__(self, data) :
        self.data = data
        self.left = None
        self.right = None
        self.height = 0
        self.balFactor = 0




class BST_AVL :
    def __init__(self, keepBal=True):
        self.root = None
        self.keepBal = keepBal


    def getHeight(self, node) :
        if (node) :
            return node.height
        else :
            return -1


    def update(self, node) :
        if (node) :
            leftHeight = self.getHeight(node.left)
            rightHeight = self.getHeight(node.right)
            node.height = max(leftHeight, rightHeight) + 1
            node.balFactor = leftHeight - rightHeight


    def rotateLL(self, A) :
        B = A.left
        A.left = B.right
        B.right = A

        self.update(A)
        self.update(B)

        return B


    def rotateRR(self, A) :
        B = A.right
        A.right = B.left
        B.left = A

        self.update(A)
        self.update(B)

        return B


    def balance(self, node) :
        self.update(node) # before rotate, update

        if (node.balFactor > 1) :
            if (node.left and node.left.balFactor < 0) : # LR rotate
                node.left = self.rotateRR(node.left) # rotate left sub tree
            return self.rotateLL(node) # LL rotate

        if (node.balFactor < -1) :
            if (node.right and node.right.balFactor > 0) : # RL rotate
                node.right = self.rotateLL(node.right) # rotate right sub tree
            return self.rotateRR(node)

        return node


    def insertRecursive(self, node, data) :
        if (not node) : # if empty space -> insert
            return Node(data)


        if (node.data > data) : # move left
            node.left = self.insertRecursive(node.left, data)
        elif (node.data < data) : # move right
            node.right = self.insertRecursive(node.right, data)
        else : # equal
            return node

        if (self.keepBal) :
            return self.balance(node)
        else :
            return node


    def insert(self, data) :
        self.root = self.insertRecursive(self.root, data)


    def deleteRecursive(self, node, data):
        if not node:
            return None


        if (data < node.data):
            node.left = self.deleteRecursive(node.left, data)
        elif (data > node.data):
            node.right = self.deleteRecursive(node.right, data)
        else: # find
            if not node.left and not node.right: # leaf node
                return None

            # has a child
            if (not node.left):
                return node.right
            elif (not node.right):
                return node.left

            # has both child
            minNode = self.getMinValueNode(node.right)
            node.data = minNode.data
            node.right = self.deleteRecursive(node.right, minNode.data)


        if (self.keepBal) :
            return self.balance(node)
        else :
            return node


    def getMinValueNode(self, node):
        current = node
        while current.left:
            current = current.left
        return current


    def delete(self, data):
        self.root = self.deleteRecursive(self.root, data)


    def inorder(self, node) :
        if (node) :
            self.inorder(node.left)
            print(node.data, end=" ")
            self.inorder(node.right)


    def preorder(self, node) :
        if (node) :
            print(node.data, end=" ")
            self.preorder(node.left)
            self.preorder(node.right)


    def display(self, prompt) :
        print(prompt, end="")
        self.preorder(self.root)
        print()


    def count_node(self) :
        if (not self.root) :
            return

        queue = [self.root]
        cur = self.root
        count = 0

        while (len(queue) != 0) :
            cur = queue.pop(0)
            count += 1

            if (cur.left) :
                queue.append(cur.left)
            if (cur.right) :
                queue.append(cur.right)

        return count


    def count_leaf(self) :
        if (not self.root) :
            return

        queue = [self.root]
        cur = self.root
        count = 0

        while (len(queue) != 0) :
            cur = queue.pop(0)

            if (cur.left) :
                queue.append(cur.left)
            if (cur.right) :
                queue.append(cur.right)
            if (not cur.left and not cur.right) :
                count += 1

        return count


    def calc_height(self) :
        return self.root.height


    def search(self, node, data):
        if not node:
            return None

        if node.data == data:
            return node.data

        if data < node.data:
            return self.search(node.left, data)
        else:
            return self.search(node.right, data)



