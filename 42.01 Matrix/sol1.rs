use std::collections::VecDeque;

struct Solution {}

impl Solution {
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let row_len = mat.len();
        let col_len = mat[0].len();
        let mut res = vec![vec![-1; col_len]; row_len];
        let mut queue: VecDeque<(usize, usize)> = VecDeque::new();

        /* 동서남북 */
        let dirs = vec![(0, -1isize), (1, 0), (0, 1), (-1isize, 0)];

        /* 0인 케이스를 시작으로 BFS  */
        for i in 0..row_len {
            for j in 0..col_len {
                if mat[i][j] == 0 {
                    res[i][j] = 0;
                    queue.push_back((i, j));
                }
            }
        }

        while let Some((x, y)) = queue.pop_front() {
            for (dx, dy) in dirs.iter() {
                let nx = x as isize + dx;
                let ny = y as isize + dy;

                if nx < 0 || ny < 0 {
                    continue;
                }

                let (nx, ny) = (nx as usize, ny as usize);

                if nx >= row_len || ny >= col_len {
                    continue;
                }

                /* 아직 0과의 거리를 체크하지 않은 경우 */
                if res[nx][ny] == -1 {
                    /* 대상을 현재 값 + 1 한다 (0이라면 1거리, 1 이상이라면 거리 중첩 */
                    res[nx][ny] = res[x][y] + 1;
                    queue.push_back((nx, ny));
                }
            }
        }
        res
    }
}

fn main() {
    let mut input = vec![];
    input.push(vec![0, 0, 0]);
    input.push(vec![0, 1, 0]);
    input.push(vec![1, 1, 1]);

    Solution::update_matrix(input);
}
