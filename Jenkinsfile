pipeline {
  agent any

  stages {
      stage('configure') {
        steps {
          dir('build') {
            sh 'cmake ../'
          }
        }
      }
      stage('build') {
        steps {
          dir('build') {
            sh 'cmake --build .'
          }
        }
      }
    }
  }
}