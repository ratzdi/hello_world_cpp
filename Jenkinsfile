pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                sh 'mkdir build_x86'
                sh 'cd build_x86'
                sh 'cmake ..'
                sh 'make'
            }
        }
    }
}
