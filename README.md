# ros_story
my first project

바보~ 희희~
22/9/28

### 2022/9/27
노드 : 프로그램 같은것

패키지 : 하나 이상의 노드를 묶어 놓은것. 패키지를 묶을수도 있는데 그것은 메타패키지라고 함.

마스터 : 노드와노드 사이의 연결 및 메시지 통신을 위한 서버와 같은 역할.
마스터 없이는 노드간 접속, 토픽, 서비스와 같은 통신을 할 수 없음.
노드(프로그램)끼리 이미 이어져있으면 마스터(서버)를 꺼도 상관없음.

publisher -> Topic -> subscriber
 (제공자)    (주제)	(구독자)

- 정보가 단방향으로만 흘러간다.
- 1대N 가능

service server -> service -> service client
    (서버)	(서비스 요청)   (클라이언트)

- 정보가 양방향으로 흘러간다.
- 1대1만 가능

액션은 피드백을 전달함.

서버가 항상 먼저 열려 있어야 한다.

하나의 노드가 여러가지 역할을 할 수 있다.

- my_publisher, my_subscriber 노드 생성
- 빌드
- 생성

### 22/9/28
노드의 이름을 정할때 띄어쓰기 안됨
토픽의 이름을 통일할것(퍼블리셔와 서브스크라이버)
영문자의 대소문자를 정확히 맞출것

어떤 이벤트가 발생했을때 호출하는 함수

#!/usr/bin/python = 이 파일을 실행할때 이 경로에 있는 파이썬을 써라! 라는 의미
리눅스를 쓸때 위에 쓴건 꼭 써주자.

rqt_graph <- 그래프를 보여주는 신기한 cmd 명령어

- topic_tutorial 패키지에 python scripts 추가
- py_publisher.py, py_subscriber.py 노드 생성
- 빌드
- 실행

- topic_second 패키지 생성
- second_pub, second_sub, py_second_pub.py, py.second_sub.py 노드 생성
- 빌드
- 실행

- 과제 1

### ROS 명령어
### roscore
- ROS Master를 실행한다.
- 노드를 켜기전 가장 먼저 실행
'''bash
    roscore
'''

### rosrun
- 노드를 실행한다.
- rosrun (패키지이름) (노드이름)
'''bash
    rosrun <패키지이름><노드이름>
'''

### 리눅스 명령어
ls
cd
cs
cm

### catkin_create_pkg
- 현재 위치한 작업 공간에 패키지를 생성한다.
- catkin_create_pkg (패키지이름) 의존선
'''bash
    catkin_create_pkg <패키지이름> <의존성1>
    <의존성2> ....
'''

'''bash
    catkin_create_pkg topic_tutorial roscpp
    rospy std_msgs
'''

#include "std_msgs/Int32.h"
1byte = 8bit
int 32bit = int 4byte
용량을 미리 정해서 이걸 쓰겠다고 선언

###catkin_create_pkg topic_test roscpp rospy std_msgs
'''bash
    패키지 만들기
'''

### 22/9/29
- [msg_tutorial](./msg_tutorial)
    - msg_tutorial 패키지 생성
    - msg 디렉토리에 Mymsg.msg 생성
    - msg_publisher, msg_subscriber, py_msg_pub.py, py_msg_sub.py 노드 생성
    - 빌드
    - 실행
- [service_tutorial](./service_tutorial)
    - service_tutorial 패키지 생성
    - srv 디렉토리에 AddTwoints 생성
    - my_server.cpp, my_client.cpp, py_server.py, py_client.py 생성
    - 빌드
    - 실행

# msg_tutorial
직접 작성한 Mymsg 메시지로 통신하는 패키지

### Publisher Node
- name :
- topic :
- msg :
- (노드 설명)

## msg 만드는법
1. 패키지 안에 msg 디렉토리를 만든다.
2. .msg 확장자의 파일을 만든다.
3. 안의 내용을 작성한다.
4. CMakelists.txt에서 설정한다.
5. 빌드 시 생성된다.

### 22/9/30
- [과제 2 yh_star](./yh_star)
    - for문 활용해서 별 찍기
        - yh_star패키지 생성
        - yh_star_pub, yh_star-sub, yh_star_pub.py, yh_star_sub.py 생성
        - 빌드
        - 실행

- [과제 2 yh_service](./yh_service)
    - yh_sevice 패키지 생성
    - yh_service, yh_clientm yh_server.py, yh_client.py 생성
    - 빌드
    - 생성

### 22/10/4
- ROS MASTER에서 실행되고 변수들을 담고 있는 서버
- ros::setParam(), ros::getParam(), rospy.set_param(), rospy.get_param()등의 함수로 사용
- command line에서 rosparam으로 사용 가능
- rosparam list
    - 파라미터 서버의 모든 파라미터를 출력
'''bash
user@gmail.com:$~ rosparam list
'''
- rosparam get <파라미터의 이름>
    - 파라미터의 값을 출력함
'''bash
user@gmail.com:$~ rosparam get <파라미터 이름>
'''
- rosparam set <파라미터 이름> [파라미터 값]
    - 파라미터의 값을 지정함
'''bash
user@gmail.com:$~ rosparam set <파라미터 이름> [파라미터 값]
'''

### teleop-twist_keyboard pkg
- input keyboard /cmd_vel topic의 geometry_msgs/Twist message publishing node.
- install

'''bash
sudo

### [param_tutorial](./param_tutorial)
- param_tutorial 패키지 생성
- calculate_server, calculate_client, calculate_server.py, calculate_client.py 노드 생성
- 빌드
- 실행

## 22/10/6
### [yh_turtle](.yh_turtle)
- yh_turtle