import functools


class Student:
    def __init__(self, age: int):
        self.age = age

    @staticmethod
    def cmp(lhs, rhs):
        if lhs.age < rhs.age:
            return -1
        elif lhs.age == rhs.age:
            return 0
        else:
            return 1

    def test(self):
        stus = []
        stus.append(Student(10))
        stus.append(Student(9))
        stus.append(Student(1))
        stus.append(Student(8))
        stus.sort(key=lambda stu: stu.age , reverse=False)
        for stu in stus:
            print(stu.age,end=',')

if __name__ == '__main__':
    n = int(eval("14/3*2".replace("/","//")))
    print(n)

