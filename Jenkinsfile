pipeline {
  agent any
  stages {
    stage('build') {
      steps {
          cmakeBuild(
            installation: 'InSearchPath',
            buildDir: 'build_x86',
            buildType: 'Unix Makefiles',
            steps: [
                      [args: 'all install', envVars: 'DESTDIR=${WORKSPACE}/artifacts']
                  ]
          )
      }
    }
  }
}