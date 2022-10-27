pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                cmakeBuild buildDir: 'build', buildType: 'Unix Makefiles', installation: 'InSearchPath', steps: [[]]
            }
        }
    }
}