### tree_delete

- tree에서 data_ref와 같은 data를 가진 요소를 삭제하는 함수를 작성하세요.

- 요소의 데이터는 free_data를 사용해서 메모리 할당을 해제해야 합니다.

- 삭제하려는 node의 child가 2개일 경우에는 node의 오른쪽 subtree 중 가장 작은 data를 가진 child가 node를 대체하여야 합니다.

  - node의 왼쪽 subtree 중 가장 큰 data를 가진 child가 node를 대체하는 방법도 가능하지만 본 예제에서는 위의 방법으로 구현하도록 합니다.

- 성공하면 1, 실패하면 0을 반환 합니다.

- data_ref와 같은 data를 가진 요소가 없다면 실패 합니다.

  ```
   int tree_delete(t_tree *tree, void *data_ref, void (*free_data)(void *));
  ```

---

"node의 왼쪽 subtree 중 가장 큰 data를 가진 child가 node를 대체하는 방법도 가능하지만 본 예제에서는 위의 방법으로 구현하도록 합니다."  
위 내용을 조금 더 발전시킨다면, "제거하는 data값에 가장 가까운 child node값으로 대체한다."

